//
// Created by max on 12/02/17.
//

#pragma once

#include <vector>
#include "MapLayer.h"
#include "MapObject.h"

using namespace std;

class MapObjectGroupLayer : public MapLayer {
    friend class Map;

public:
    MapObjectGroupLayer(Map *map);

    void addObject(string name, MapObject *object);

private:
    std::vector<MapObject *> *_objects_list;
};