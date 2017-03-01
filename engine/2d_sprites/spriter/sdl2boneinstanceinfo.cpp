#include <spriterengine/global/settings.h>
#include "sdl2boneinstanceinfo.h"

namespace SpriterEngine {

    SDL2BoneInstanceInfo::SDL2BoneInstanceInfo(point initialSize, SDL_Renderer *validRenderWindow) :
            BoneInstanceInfo(initialSize),
            renderWindow(validRenderWindow) {
//		boneShape.setPointCount(4);
//
//		boneShape.setPoint(0, sf::Vector2f(0, initialSize.y/2.0));
//		boneShape.setPoint(1, sf::Vector2f(4, 0));
//		boneShape.setPoint(2, sf::Vector2f(initialSize.x, initialSize.y/2.0));
//		boneShape.setPoint(3, sf::Vector2f(4, initialSize.y));
//
//		boneShape.setOrigin(0, initialSize.y/2.0);
//
//		boneShape.setFillColor(sf::Color(0, 0, 255, 50));
//
//		boneShape.setOutlineColor(sf::Color::White);
//		boneShape.setOutlineThickness(1);
    }

    void SDL2BoneInstanceInfo::render() {
        if (Settings::renderDebugBones) {
//			boneShape.setPosition(getPosition().x, getPosition().y);
//			boneShape.setRotation(toDegrees(getAngle()));
//			boneShape.setScale(getScale().x, getScale().y);
//			renderWindow->draw(boneShape);
        }
    }

}
