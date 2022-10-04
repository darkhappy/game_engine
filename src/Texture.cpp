//
// Created by Jean-Philippe on 2022-09-27.
//

#include "Texture.h"
#include <SDL2/SDL_image.h>

Texture::Texture(const char *path) : Texture(*IMG_Load(path)) {}

Texture::Texture(const SDL_Surface &surface, bool isFont) {
    this->width = surface.w;
    this->height = surface.h;

    glGenTextures(1, &textureID);
    bind();

    if (isFont) {
#ifdef __APPLE__
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height,
                     0, GL_BGRA, GL_UNSIGNED_BYTE, surface.pixels);
#else
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height,
                     0, GL_RGBA, GL_UNSIGNED_BYTE, surface.pixels);
#endif
    } else {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height,
                     0, GL_RGBA, GL_UNSIGNED_BYTE, surface.pixels);
    }

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    SDL_FreeSurface((SDL_Surface *) &surface);
}

Texture::~Texture() {
    glDeleteTextures(1, &textureID);
}

void Texture::bind() const {
    glBindTexture(GL_TEXTURE_2D, textureID);
}

GLuint Texture::getTextureID() const {
    return textureID;
}

int Texture::getWidth() const {
    return width;
}

int Texture::getHeight() const {
    return height;
}
