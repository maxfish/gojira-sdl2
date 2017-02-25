//
// Created by max on 22/02/17.
//

#include <Box2D/Dynamics/b2World.h>
#include <Box2D/Dynamics/b2Body.h>
#include <Box2D/Collision/Shapes/b2CircleShape.h>
#include <Box2D/Dynamics/b2Fixture.h>
#include "PhysicCircle.h"

PhysicCircle::PhysicCircle(b2World *world, float32 pos_x, float32 pos_y, float32 radius) : PhysicObject(world) {
    _world = world;
    _radius = radius;

    b2BodyDef body_definition;
    body_definition.type = b2_dynamicBody;
    body_definition.position.Set(pos_x, pos_y);
    _body = world->CreateBody(&body_definition);

    b2CircleShape *dynamicCircle = new b2CircleShape();
    dynamicCircle->m_radius = radius;
    b2FixtureDef fixtureDef;
    fixtureDef.shape = dynamicCircle;
    fixtureDef.density = DEFAULT_DENSITY;
    fixtureDef.friction = DEFAULT_FRICTION;
    _fixture = _body->CreateFixture(&fixtureDef);
}
