#include "sdl2soundfile.h"
#include "sdl2soundobjectinforeference.h"

namespace SpriterEngine {
    SDL2SoundFile::SDL2SoundFile(std::string initialFilePath) :
            SoundFile(initialFilePath) {
        initializeFile();
    }

    void SDL2SoundFile::initializeFile() {
//		if (!buffer.loadFromFile(path()))
//		{
//			Settings::error("SDL2SoundFile::initializeFile - SDL sound buffer unable to load file from path \"" + path() + "\"");
//		}
    }

    SoundObjectInfoReference *SDL2SoundFile::newSoundInfoReference() {
        return nullptr;
//		return new SDL2SoundObjectInfoReference(buffer);
    }

}
