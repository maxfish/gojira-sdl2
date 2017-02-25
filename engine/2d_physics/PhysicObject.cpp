//
// Created by max on 22/02/17.
//

#include "PhysicObject.h"

PhysicObject::PhysicObject(b2World *world) {
    _world = world;
}

PhysicObject::~PhysicObject() {
    _fixture = nullptr;
    _world->DestroyBody(_body);
}

void PhysicObject::setCustomData(void *id) {
    _body->SetUserData(id);
}
