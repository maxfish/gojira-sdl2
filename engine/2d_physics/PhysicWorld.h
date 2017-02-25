//
// Created by max on 22/02/17.
//

#pragma once

#include <vector>
#include "PhysicObject.h"

class PhysicWorld {
public:
    PhysicWorld(b2Vec2 gravity);

    ~PhysicWorld();

private:
    b2World *_world;
    b2Vec2 _gravity;
};
