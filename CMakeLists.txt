cmake_minimum_required(VERSION 3.23)
project(sdl_library)

set(CMAKE_CXX_STANDARD 17)

# Include SDL2
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# Include OpenGL
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})

add_executable(sdl_library src/main.cpp src/Application.cpp src/Application.h src/Window.cpp src/Window.h src/SDL2Window.cpp src/SDL2Window.h src/OpenGLWindow.cpp src/OpenGLWindow.h src/Event.cpp src/Event.h)

target_link_libraries(sdl_library ${SDL2_LIBRARIES} ${OPENGL_LIBRARIES})