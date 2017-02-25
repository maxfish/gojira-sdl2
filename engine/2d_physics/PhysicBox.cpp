//
// Created by max on 22/02/17.
//

#include <Box2D/Dynamics/b2Body.h>
#include <Box2D/Collision/Shapes/b2PolygonShape.h>
#include <Box2D/Dynamics/b2Fixture.h>
#include "PhysicBox.h"

PhysicBox::PhysicBox(b2World *world, float32 pos_x, float32 pos_y, float32 half_width, float32 half_height, bool dynamic) : PhysicObject(
        world) {

    _world = world;
    _half_width = half_width;
    _half_height = half_height;

    b2BodyDef body_definition;
    body_definition.type = dynamic ? b2_dynamicBody : b2_staticBody;
    body_definition.position.Set(pos_x, pos_y);
    _body = world->CreateBody(&body_definition);
    b2PolygonShape *dynamicBox = new b2PolygonShape();
    dynamicBox->SetAsBox(half_width, half_height);
    b2FixtureDef fixtureDef;
    fixtureDef.shape = dynamicBox;
    fixtureDef.density = DEFAULT_DENSITY;
    fixtureDef.friction = DEFAULT_FRICTION;
    _fixture = _body->CreateFixture(&fixtureDef);
}

