//
// Created by Jean-Philippe on 2022-09-28.
//

#include "TTFont.h"

TTFont::TTFont(const char *path, int size, const std::string &text, SDL_Color color) : Texture(nullptr) {
    this->color = color;
    this->text = text;
    this->size = size;
    this->path = path;
    font = TTF_OpenFont(path, size);

    load();
}

TTFont::~TTFont() {
    TTF_CloseFont(font);
}

void TTFont::load() {
    SDL_Surface *surface = TTF_RenderUTF8_Blended(font, text.c_str(), color);
    // Fix the text being weirdly rendered
    unsigned int realPitch = surface->w * surface->format->BytesPerPixel;
    auto *src = (unsigned char *) surface->pixels;
    unsigned char *dst = src;
    for (size_t y = 0; y < surface->h; y++) {
        memmove(dst, src, realPitch);
        dst += realPitch;
        src += surface->pitch;
    }
    surface->pitch = realPitch;

    glGenTextures(1, &textureID);
    bind();


#ifdef __APPLE__
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surface->w, surface->h,
                 0, GL_BGRA, GL_UNSIGNED_BYTE, surface->pixels);
#else
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surface.w, surface.h,
                 0, GL_RGBA, GL_UNSIGNED_BYTE, surface.pixels);
#endif
    width = surface->w;
    height = surface->h;
    SDL_FreeSurface(surface);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    unbind();
}

void TTFont::setText(const std::string &text) {
    this->text = text;
    load();
}

void TTFont::setColor(SDL_Color color) {
    this->color = color;
    load();
}

void TTFont::setSize(int newSize) {
    TTF_CloseFont(font);
    this->size = newSize;
    font = TTF_OpenFont(path.c_str(), newSize);
    load();
}

int TTFont::getWidth() const {
    return width;
}

int TTFont::getHeight() const {
    return height;
}

int TTFont::getSize() const {
    return size;
}

SDL_Color TTFont::getColour() const {
    return color;
}
