//
// Created by max on 22/02/17.
//

#pragma once

#include "PhysicObject.h"

class PhysicCircle : public PhysicObject {
public:
    PhysicCircle(b2World *world, float32 pos_x, float32 pos_y, float32 radius);

private:
    float32 _radius;
};
