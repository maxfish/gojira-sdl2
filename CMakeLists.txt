project(gojira_sdl2 CXX)

cmake_minimum_required(VERSION 3.6)
include(ExternalProject)
set(CMAKE_CXX_STANDARD 11)

# Setup SDL2
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

# Box2D library
set(LIB_BOX2D_DIR "${CMAKE_CURRENT_SOURCE_DIR}/externals/box2d/Box2D/Box2D")
ExternalProject_Add(box2d
        SOURCE_DIR ${LIB_BOX2D_DIR}
        CMAKE_ARGS "-DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_DIR}"
        INSTALL_COMMAND ""
        UPDATE_COMMAND ""
        )
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/externals/box2d/Box2D")
#include_directories("${CMAKE_CURRENT_SOURCE_DIR}/externals/box2d/Box2D/Box2D")
file(GLOB_RECURSE BOX2D_SRC "${LIB_BOX2D_DIR}/*.cpp")

# Spriter library
set(LIB_SPRITERPLUSPLUS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/externals/SpriterPlusPlus/spriterengine")
ExternalProject_Add(spriterplusplus
        SOURCE_DIR ${LIB_SPRITERPLUSPLUS_DIR}
        CMAKE_ARGS "-DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_DIR}"
        INSTALL_COMMAND ""
        UPDATE_COMMAND ""
        )
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/externals/SpriterPlusPlus")
file(GLOB_RECURSE SPRITERPLUSPLUS_SRC "${LIB_SPRITERPLUSPLUS_DIR}/*.cpp")
#file(GLOB_RECURSE SPRITERPLUSPLUS_INCLUDE "${LIB_SPRITERPLUSPLUS_DIR}/*.h")

# Setup library
file(GLOB_RECURSE ENGINE_SRC "engine/*.cpp")
file(GLOB_RECURSE ENGINE_INCLUDE "engine/*.h")

include_directories(. third_parties)

set(SOURCE_FILES ${ENGINE_SRC} ${ENGINE_INCLUDE}
        ${BOX2D_SRC}
        ${SPRITERPLUSPLUS_SRC}
        )
add_library(gojira_sdl2 ${SOURCE_FILES})
add_dependencies(gojira_sdl2 box2d spriterplusplus)
