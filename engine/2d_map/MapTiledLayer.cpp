//
// Created by max on 12/02/17.
//

#include "engine/2d_map/MapTiledLayer.h"

MapTiledLayer::MapTiledLayer(Map *map) : MapLayer(map) {
}

void MapTiledLayer::setData(vector<Uint32> *data) {
    _tiles = data;
}

void MapTiledLayer::draw(Graphics *graphics) {
    if (!_visible) {
        return;
    }

    // TODO: The layer should have its own offset

    SDL_Rect map_viewport = _map->getViewport();
    SDL_Point map_offset = _map->getOffset();
    Uint8 tile_width = _map->getTileWidth();
    Uint8 tile_height = _map->getTileHeight();

    Uint8 num_tiles_rows = (Uint8) (map_viewport.h / tile_height + 1);
    Uint8 num_tiles_cols = (Uint8) (map_viewport.w / tile_width + 1);
    SDL_Point tiles_offset = {-map_offset.x % tile_width, -map_offset.y % tile_height};

    Uint16 tile_y = (Uint16) (map_offset.y / tile_height);
    for (Uint8 y = 0; y < num_tiles_rows; y++) {
        Uint16 tile_x = (Uint16) (map_offset.x / tile_width);
        Uint32 tile_index = tile_x + tile_y * _width;
        int draw_y = y * tile_height + tiles_offset.y;

        for (Uint8 x = 0; x < num_tiles_cols; x++) {
            Uint32 gid = _tiles->at(tile_index);
            if (gid != 0) {
                MapTileSet *set = _map->tileSetFromGid(gid);
                int draw_x = x * tile_width + tiles_offset.x;
                set->drawTile(graphics, gid, draw_x, draw_y);
            }
            tile_x++;
            tile_index++;
        }
        tile_y++;
    }
}

bool MapTiledLayer::rectCollides(SDL_Rect rect, SDL_Point velocity) {
    // TODO : WIP
//    Uint8 tile_width = _map->getTileWidth();
//    Uint8 tile_height = _map->getTileHeight();
//    SDL_Rect tile_rect = {0,0,tile_width,tile_height};
//
//    for (Uint8 tile_y=0; tile_y<_height; tile_y++) {
//    for (Uint8 tile_x=0; tile_x<_width; tile_x++) {
//        Uint32 tile_index = tile_x + tile_y * _width;
//        Uint32 gid = _tiles->at(tile_index);
//        if (gid != 0) {
//            MapTileSet *set = _map->tileSetFromGid(gid);
//        }
//    }
//    }
//    MapTileSet *set = _map->tileSetFromGid(gid);
    return false;
}

