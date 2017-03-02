project(gojira_sdl2 CXX)

cmake_minimum_required(VERSION 3.6)
include(ExternalProject)
set(CMAKE_CXX_STANDARD 11)


################################################################
# SDL 2                                                        #
################################################################
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
include_directories(
        /usr/local/include
        ${SDL2_INCLUDE_DIR}
        ${SDL2_IMAGE_INCLUDE_DIR}
        ${SDL2_TTF_INCLUDE_DIR}
)


################################################################
# External libraries                                           #
################################################################
set(BOX2D_BUILD_STATIC TRUE)
set(BOX2D_BUILD_EXAMPLES FALSE)
include_directories(externals/box2d/Box2D)
include_directories(externals/SpriterPlusPlus)
add_subdirectory(externals)


################################################################
# Main libraries                                               #
################################################################
file(GLOB_RECURSE ENGINE_SRC "engine/*.cpp")
file(GLOB_RECURSE ENGINE_INCLUDE "engine/*.h")

include_directories(. third_parties)

set(SOURCE_FILES ${ENGINE_SRC} ${ENGINE_INCLUDE})
add_library(gojira_sdl2 ${SOURCE_FILES})
