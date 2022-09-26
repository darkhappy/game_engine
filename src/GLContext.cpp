/// @file GLContext.cpp
/// @brief Contains the implementation of the GLContext class in GLContext.h
/// @author Jean-Philippe (me\@darkh.app)

#include "GLContext.h"

GLContext::GLContext(const char *title, int windowX, int windowY, int width, int height, unsigned int flags)
        : Window(title, windowX, windowY, width, height, flags | SDL_WINDOW_OPENGL) {
    TTF_Init();

    context = SDL_GL_CreateContext(window);
    projectionMatrix.loadOrthographic(width, height);
    ttfFont = TTF_OpenFont("../assets/fonts/comic.ttf", 42);

    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);

    // Load an image
    /* SDL_Surface *surface = IMG_Load("../assets/images/vim.png");
     * glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surface->w, surface->h,
     *             0, GL_RGBA, GL_UNSIGNED_BYTE, surface->pixels);
     * SDL_FreeSurface(surface);
     */

    // Load text
    SDL_Surface *surface = TTF_RenderText_Blended(ttfFont, "we love vim baby", {255, 150, 150, 255});
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

#ifdef __APPLE__
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surface->w, surface->h,
                 0, GL_BGRA, GL_UNSIGNED_BYTE, surface->pixels);
#else
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surface->w, surface->h,
                 0, GL_BGRA, GL_UNSIGNED_BYTE, surface->pixels);
#endif

    SDL_FreeSurface(surface);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

GLContext::~GLContext() {
    TTF_CloseFont(ttfFont);
    glDeleteTextures(1, &textureID);
    SDL_GL_DeleteContext(context);
}

void GLContext::clear() {
    glClear(GL_COLOR_BUFFER_BIT);
}

void GLContext::update() {
    SDL_GL_SwapWindow(window);
}

void GLContext::draw() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMultMatrixd(projectionMatrix.elements);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glBegin(GL_QUADS);
    glTexCoord2d(0, 0);
    glVertex3d(50, 50, 0);
    glTexCoord2d(1, 0);
    glVertex3d(1230, 50, 0);
    glTexCoord2d(1, 1);
    glVertex3d(1230, 150, 0);
    glTexCoord2d(0, 1);
    glVertex3d(50, 150, 0);
    glEnd();
}
