cmake_minimum_required(VERSION 3.19)

project(game_engine VERSION 0.1.0
        DESCRIPTION "A game engine"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

# Include SDL2
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# Include OpenGL
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})

# Include our math library that we wrote in lib/math
include_directories(include/math/include)

# Add the executable
add_executable(game
        src/main.cpp
        src/Window.cpp
        src/Event.cpp
        src/GLContext.cpp
        src/Application.cpp)

target_link_libraries(game PUBLIC ${SDL2_LIBRARIES} ${OPENGL_LIBRARIES} math)