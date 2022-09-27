/// @file GLContext.cpp
/// @brief Contains the implementation of the GLContext class in GLContext.h
/// @author Jean-Philippe (me\@darkh.app)

#include <string>
#include "GLContext.h"

using std::to_string;

GLContext::GLContext(const char *title, int windowX, int windowY, int width, int height, unsigned int flags)
        : Window(title, windowX, windowY, width, height, flags | SDL_WINDOW_OPENGL) {
    TTF_Init();

    context = SDL_GL_CreateContext(window);
    projectionMatrix.loadOrthographic(width, height);
    ttfFont = TTF_OpenFont("../assets/fonts/comic.ttf", 42);

    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

GLContext::~GLContext() {
    TTF_CloseFont(ttfFont);
    SDL_GL_DeleteContext(context);
}

void GLContext::clear() {
    glClear(GL_COLOR_BUFFER_BIT);
}

void GLContext::update() {
    SDL_GL_SwapWindow(window);
}

void GLContext::showFPS(int fps) {
    // Load text
    SDL_Surface *surface = TTF_RenderText_Blended(ttfFont, (to_string(fps) + " fps lol").c_str(), {255, 255, 255, 255});
    // Fix the text being wacky
    unsigned int realPitch = surface->w * surface->format->BytesPerPixel;
    auto *src = (unsigned char *) surface->pixels;
    unsigned char *dst = src;
    for (size_t y = 0; y < surface->h; y++) {
        memmove(dst, src, realPitch);
        dst += realPitch;
        src += surface->pitch;
    }
    surface->pitch = realPitch;

    // Create texture
    unsigned int texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

#ifdef __APPLE__
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surface->w, surface->h, 0, GL_BGRA, GL_UNSIGNED_BYTE, surface->pixels);
#else
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surface->w, surface->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, surface->pixels);
#endif

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // Draw texture
    GLContext::drawSquare(0, 0, surface->w, 0, 0, surface->h, surface->w, surface->h);


    SDL_FreeSurface(surface);
}

void GLContext::draw() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMultMatrixd(projectionMatrix.elements);

}

void GLContext::drawSquare(double topLeftX, double topLeftY, double topRightX, double topRightY, double bottomLeftX,
                           double bottomLeftY, double bottomRightX, double bottomRightY) {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glBegin(GL_QUADS);
    glTexCoord2d(0, 0);
    glVertex2d(topLeftX, topLeftY);
    glTexCoord2d(1, 0);
    glVertex2d(topRightX, topRightY);
    glTexCoord2d(1, 1);
    glVertex2d(bottomRightX, bottomRightY);
    glTexCoord2d(0, 1);
    glVertex2d(bottomLeftX, bottomLeftY);
    glEnd();
}
