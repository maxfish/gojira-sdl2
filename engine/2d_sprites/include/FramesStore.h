//
// Created by Massimiliano Pesce on 07/12/2016.
//

#pragma once

#include <map>
#include <SDL_Image.h>
#include <engine/core/include/Graphics.h>
#include <engine/2d_sprites/include/Frame.h>
#include <engine/2d_sprites/include/Animation.h>

class FramesStore {
public:
    static const int DEFAULT_FPS = 25;

    FramesStore(Graphics &graphics);

    void load(std::string file_path, std::string file_name);

    SDL_Texture *getImage(std::string file_name);

    Animation *getAnimation(std::string animation_name);

    Frame *getFrame(std::string frame_name);

    int getAnimationsFPS();

private:
    Graphics *_graphics;

    int _fps;

    std::map<std::string, SDL_Texture *> _images;
    std::map<std::string, Frame *> _frames;
    std::map<std::string, Animation *> _animations;
};
