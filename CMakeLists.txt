cmake_minimum_required(VERSION 3.6)
include(ExternalProject)
set(CMAKE_CXX_STANDARD 14)

project(gojira_sdl2)

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

# Setup library
file(GLOB_RECURSE ENGINE_SRC "engine/*.cpp")
file(GLOB_RECURSE ENGINE_INCLUDE "engine/*.h")

include_directories(. third_parties)

set(SOURCE_FILES ${ENGINE_SRC} ${ENGINE_INCLUDE})
add_library(gojira_sdl2 ${SOURCE_FILES})