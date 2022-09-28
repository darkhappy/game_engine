cmake_minimum_required(VERSION 3.19)

project(game_engine VERSION 0.1.0
        DESCRIPTION "A game engine"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

# Include SDL2
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# Include SDL2_image
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_IMAGE_INCLUDE_DIRS})

# Include SDL2_ttf
find_package(SDL2_ttf REQUIRED)
include_directories(${SDL2TTF_INCLUDE_DIRS})

# Include OpenGL
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})

# Build our math library
add_subdirectory(include/math)

# Include our math library
include_directories(include/math/include)

# Add the executable
add_executable(game
        src/main.cpp
        src/Window.cpp
        src/Event.cpp
        src/GLContext.cpp
        src/Application.cpp
        src/Singleton.cpp
        src/Chronometer.cpp
        src/Texture.cpp
        src/Screensaver.cpp
        src/TTFont.cpp)

target_link_libraries(game PUBLIC ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} ${SDL2_TTF_LIBRARY} ${OPENGL_LIBRARIES} math_library)