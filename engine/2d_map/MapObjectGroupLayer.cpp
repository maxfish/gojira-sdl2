//
// Created by max on 18/02/17.
//

#include "engine/2d_map/MapObjectGroupLayer.h"

MapObjectGroupLayer::MapObjectGroupLayer(Map *map) : MapLayer(map) {
    _objects_list = new std::vector<MapObject *>;
}

void MapObjectGroupLayer::addObject(string name, MapObject *object) {
    _objects_list->push_back(object);
}
