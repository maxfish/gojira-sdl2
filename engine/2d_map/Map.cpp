//
// Created by max on 12/02/17.
//

#include "engine/2d_map/Map.h"
#include <engine/core/Utils.hpp>
#include <engine/2d_map/MapTiledLayer.h>
#include <engine/2d_map/MapObjectGroupLayer.h>


Map::Map(Graphics &graphics) {
    _graphics = &graphics;

    _offset = {0, 0};

    // The viewport defaults to the renderer size
    int w, h;
    SDL_GetRendererOutputSize(_graphics->getRenderer(), &w, &h);
    SDL_Rect viewport = {0, 0, w, h};
    this->setViewport(viewport);
}

void Map::setViewport(SDL_Rect viewport) {
    _viewport = viewport;
}

SDL_Rect Map::getViewport() {
    return _viewport;
}

void Map::setOffset(SDL_Point offset) {
    _offset = offset;
}

SDL_Point Map::getOffset() {
    return _offset;
}

Uint8 Map::getTileWidth() {
    return _tile_width;
}

Uint8 Map::getTileHeight() {
    return _tile_height;
}

void Map::draw() {
    SDL_RenderSetClipRect(_graphics->getRenderer(), &_viewport);
    for (MapLayer *layer : *_layers) {
        layer->draw(_graphics);
    }
    SDL_RenderSetClipRect(_graphics->getRenderer(), NULL);
}

MapTileSet *Map::tileSetFromGid(Uint32 global_index) {
    for (MapTileSet *tileSet : *_tile_sets) {
        global_index &= MapTileSet::GID_MASK;
        if (global_index >= tileSet->_first_gid && global_index < tileSet->_first_gid + tileSet->_tiles_count) {
            return tileSet;
        }
    }
    return nullptr;
}

static MapLayerType _layerTypeFromString(string type) {
    if (type == "tilelayer") {
        return MapLayerType_Tiles;
    } else if (type == "objectgroup") {
        return MapLayerType_Objects;
    }
    return MapLayerType_Unknown;
}

void Map::loadFromJSON(string file_path, string file_name) {
    nlohmann::json json = Utils::jsonFromFile(file_path + "/" + file_name);
    if (json == nullptr) {
        SDL_Log("Error - Couldn't open file '%s'", file_path.c_str());
        return;
    }

    //"version": 1,
    //"orientation":"orthogonal",
    //"renderorder":"right-down",
    _width = json["width"];
    _height = json["height"];
    _tile_width = json["tilewidth"];
    _tile_height = json["tileheight"];
    _next_object_id = json["nextobjectid"];
    _layers = new vector<MapLayer *>;
    _tile_sets = new vector<MapTileSet *>;

    vector<nlohmann::json> layers = json["layers"];
    for (nlohmann::json layer_json : layers) {
        string type = layer_json["type"];

        MapLayer *layer = nullptr;
        MapLayerType layerType = _layerTypeFromString(type);
        switch (layerType) {
            case MapLayerType_Tiles:
                layer = new MapTiledLayer(this);
                break;
            case MapLayerType_Objects:
                layer = new MapObjectGroupLayer(this);
                break;
            case MapLayerType_Unknown:
                SDL_Log("MAP: Error loading layer type '%s'", type.c_str());
                break;
        }

        if (layer) {
            layer->_name = layer_json["name"];
            layer->_width = layer_json["width"];
            layer->_height = layer_json["height"];
            layer->_opacity = layer_json["opacity"];
            layer->_offset_x = layer_json["x"];
            layer->_offset_y = layer_json["y"];
            layer->_visible = layer_json["visible"];

            switch (layerType) {
                case MapLayerType_Tiles: {
                    // TODO: Find a better way to load the array
                    vector<Uint32> *data = new vector<Uint32>;
                    for (Uint32 tile : layer_json["data"]) {
                        data->push_back(tile);
                    }
                    ((MapTiledLayer *) layer)->setData(data);
                    break;
                }
                case MapLayerType_Objects: {
                    //TODO: Support for polylines, ellipses and polygons
                    vector<nlohmann::json> objects = layer_json["objects"];
                    for (nlohmann::json object_json : objects) {
                        MapObject *object = new MapObject();
                        object->_id = object_json["id"];
                        object->_name = object_json["name"];
                        object->_type = object_json["type"];
                        object->_visible = object_json["visible"];
                        object->_rect = Utils::rectFromJson(object_json);
                        object->_rotation = object_json["rotation"];
                        ((MapObjectGroupLayer *) layer)->addObject(object->_name, object);
                    }
                    break;
                }
                default:
                    break;
            }

            _layers->push_back(layer);
        }
    }

    vector<nlohmann::json> tilesets = json["tilesets"];
    for (nlohmann::json tileset_json : tilesets) {
        MapTileSet *tileset = new MapTileSet(this);
        tileset->_name = tileset_json["name"];
        tileset->_image = tileset_json["image"];
        string image_path = file_path + "/" + tileset->_image;
        tileset->_image_data = _graphics->loadTexture(image_path);
        tileset->_image_width = tileset_json["imagewidth"];
        tileset->_image_height = tileset_json["imageheight"];
        tileset->_margin = tileset_json["margin"];
        tileset->_spacing = tileset_json["spacing"];
        tileset->_first_gid = tileset_json["firstgid"];
        tileset->_tiles_count = tileset_json["tilecount"];
        tileset->_tile_width = tileset_json["tilewidth"];
        tileset->_tile_height = tileset_json["tileheight"];
        tileset->_tiles_on_a_row = tileset_json["columns"];

        if (tileset_json.find("tileproperties") != tileset_json.end()) {
            std::map<std::string, nlohmann::json> properties_values = tileset_json["tileproperties"];
            for (auto tile_entry : properties_values) {
                std::string tile_id = tile_entry.first;
                Uint32 tile_id_int = (Uint32) std::atol(tile_id.c_str());
                std::map<std::string, nlohmann::json> properties_json = tile_entry.second;
                for (auto property_entry : properties_json) {
                    std::string property_name = property_entry.first;
                    if (property_name == "collision") {
                        bool property_value = property_entry.second;
                        (*(tileset->_tile_collision))[tile_id_int] = property_value;
                    }
                }
            }
        }

        _tile_sets->push_back(tileset);
    }

    SDL_Log("Map '%s/%s' loaded.", file_path.c_str(), file_name.c_str());
}
