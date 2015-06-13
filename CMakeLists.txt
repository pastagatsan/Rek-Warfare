project(rekwarfare)
cmake_minimum_required(VERSION 2.8)

# Point to our own cmake modules
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMakeModules)

# Find SDL2
find_package(SDL2 REQUIRED)
find_package (SDL2_image REQUIRED)

# Add global definitions
add_definitions("-std=c++11 -g -Wall -pedantic-errors -Wextra")
include_directories(${SDL2_INCLUDE_DIR})

add_executable(rekwarfare main.cpp Win.cpp graphics/Drawer.cpp graphics/Texture.cpp ent/Entity.cpp
    ent/Mob.cpp ent/Player.cpp)
install(TARGETS rekwarfare DESTINATION bin)
target_link_libraries(rekwarfare ${SDL2_LIBRARIES} ${SDLIMAGE_LIBRARY})
