//
// Created by Jean-Philippe on 2022-09-27.
//

#include "Texture.h"

Texture::Texture(const char *path) {
    if (path == nullptr) {
        return;
    }
    SDL_Surface *surface = IMG_Load(path);

    if (surface != nullptr) {
        glGenTextures(1, &textureID);
        bind();

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surface->w, surface->h,
                     0, GL_RGBA, GL_UNSIGNED_BYTE, surface->pixels);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        unbind();
    }

    SDL_FreeSurface(surface);
}

Texture::~Texture() {
    glDeleteTextures(1, &textureID);
}

void Texture::bind() const {
    glBindTexture(GL_TEXTURE_2D, textureID);
}

void Texture::unbind() {
    glBindTexture(GL_TEXTURE_2D, 0);
}

GLuint Texture::getTextureID() const {
    return textureID;
}

