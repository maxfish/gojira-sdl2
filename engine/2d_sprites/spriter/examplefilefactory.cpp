#include <SDL_system.h>
#include "examplefilefactory.h"

#include "jsonspriterfiledocumentwrapper.h"

#include "sdl2imagefile.h"
#include "sdl2atlasfile.h"
#include "sdl2soundfile.h"

namespace SpriterEngine {
    ExampleFileFactory::ExampleFileFactory(SDL_Renderer *validRenderWindow) :
            renderWindow(validRenderWindow) {
    }

    ImageFile *ExampleFileFactory::newImageFile(const std::string &initialFilePath, point initialDefaultPivot,
                                                atlasdata atlasData) {
        return new SDL2ImageFile(initialFilePath, initialDefaultPivot, renderWindow);
    }

    AtlasFile *ExampleFileFactory::newAtlasFile(const std::string &initialFilePath) {
        return new SDL2AtlasFile(renderWindow, initialFilePath);

    }

    SoundFile *ExampleFileFactory::newSoundFile(const std::string &initialFilePath) {
//		return new SDL2SoundFile(initialFilePath);
        return nullptr;
    }

    SpriterFileDocumentWrapper *ExampleFileFactory::newScmlDocumentWrapper() {
        return nullptr;
    }

    SpriterFileDocumentWrapper *ExampleFileFactory::newSconDocumentWrapper() {
        return new JSONSpriterFileDocumentWrapper();
    }
}
