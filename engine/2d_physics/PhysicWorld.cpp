//
// Created by max on 22/02/17.
//

#include <Box2D/Dynamics/b2World.h>
#include "PhysicWorld.h"
#include "PhysicObject.h"

PhysicWorld::PhysicWorld(b2Vec2 gravity) {
    _world = new b2World(gravity);
    _gravity = gravity;
}

PhysicWorld::~PhysicWorld() {
    delete(_world);
}
