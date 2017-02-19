//
// Created by max on 18/02/17.
//

#pragma once

#include "MapLayer.h"

class MapObject {
    friend class Map;

public:
    MapObject();

protected:
    Uint16 _id;
    string _name;
    string _type;
    bool _visible;
    SDL_Rect _rect;
    float _rotation;
};