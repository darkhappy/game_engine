cmake_minimum_required(VERSION 3.23)
project(sdl_library)

set(CMAKE_CXX_STANDARD 17)

# Include SDL2
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# Include OpenGL
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})

add_executable(sdl_library main.cpp Application.cpp Application.h Window.cpp Window.h SDL2Window.cpp SDL2Window.h OpenGLWindow.cpp OpenGLWindow.h Event.cpp Event.h)

target_link_libraries(sdl_library ${SDL2_LIBRARIES} ${OPENGL_LIBRARIES})