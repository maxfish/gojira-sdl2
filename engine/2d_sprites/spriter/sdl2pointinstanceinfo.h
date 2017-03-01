#ifndef SFMLPOINTINSTANCEINFO_H
#define SFMLPOINTINSTANCEINFO_H

#include <SDL_render.h>
#include <spriterengine/objectinfo/pointinstanceinfo.h>

namespace SpriterEngine {

    class SDL2PointInstanceInfo : public PointInstanceInfo {
    public:
        SDL2PointInstanceInfo(SDL_Renderer *validRenderWindow);

        void render() override;

    private:
        SDL_Renderer *renderWindow;

//		sf::CircleShape circle;
    };

}

#endif // SFMLPOINTINSTANCEINFO_H
