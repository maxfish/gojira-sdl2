//
// Created by max on 22/02/17.
//

#pragma once

#include <Box2D/Dynamics/b2World.h>
#include <Box2D/Dynamics/b2Body.h>

class PhysicObject {
    friend class PhysicWorld;

public:
    static const float32 DEFAULT_DENSITY = 1.0;
    static const float32 DEFAULT_FRICTION = 0.3;

    PhysicObject(b2World *world);

    ~PhysicObject();

    virtual void setCustomData(void *id);

protected:
    b2World *_world;
    b2Body *_body;
    b2Fixture *_fixture;
};
