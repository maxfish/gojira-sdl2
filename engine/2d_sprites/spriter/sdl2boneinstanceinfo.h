#ifndef SFMLBONEINSTANCEINFO_H
#define SFMLBONEINSTANCEINFO_H

#include <SDL_render.h>
#include <spriterengine/objectinfo/boneinstanceinfo.h>

namespace SpriterEngine {

    class SDL2BoneInstanceInfo : public BoneInstanceInfo {
    public:
        SDL2BoneInstanceInfo(point initialSize, SDL_Renderer *validRenderWindow);

        void render() override;

    private:
        SDL_Renderer *renderWindow;

//		sf::ConvexShape boneShape;
    };

}

#endif // SFMLBONEINSTANCEINFO_H
