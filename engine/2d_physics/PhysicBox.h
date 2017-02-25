//
// Created by max on 22/02/17.
//

#pragma once

#include "PhysicObject.h"

class PhysicBox : public PhysicObject {
public:
    PhysicBox(b2World *world, float32 posx, float32 posy, float32 halfWidth, float32 halfHeight, bool dynamic=false);

private:
    float32 _half_width;
    float32 _half_height;
};
