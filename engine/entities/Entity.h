//
// Created by Massimiliano Pesce on 05/02/17.
//

#pragma once

#include <engine/core/Graphics.h>
#include <engine/2d_sprites/Sprite.h>

class Entity {
public:
    Entity();

    virtual void update(float gameSpeed);

    virtual void draw(Graphics &graphics);

    virtual void setPosition(float x, float y);

protected:
    float _position_x;
    float _position_y;
};