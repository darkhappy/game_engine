//
// Created by Jean-Philippe on 2022-09-28.
//

#include "TTFont.h"

TTFont::TTFont(const char *path, int size, const std::string &text, SDL_Color color) {
    this->color = color;
    this->text = text;
    this->size = size;
    this->path = path;
    font = TTF_OpenFont(path, size);
}

TTFont::~TTFont() {
    TTF_CloseFont(font);
}

SDL_Surface *TTFont::getSurface() {
    surface = TTF_RenderUTF8_Blended(font, text.c_str(), color);

    // Fix the text being weirdly rendered
    int realPitch = surface->w * surface->format->BytesPerPixel;
    auto *src = (unsigned char *) surface->pixels;
    unsigned char *dst = src;
    for (size_t y = 0; y < surface->h; y++) {
        memmove(dst, src, realPitch);
        dst += realPitch;
        src += surface->pitch;
    }
    surface->pitch = realPitch;

    return surface;
}

SDL_Surface *TTFont::setText(const std::string &text) {
    this->text = text;
    return getSurface();
}

SDL_Surface *TTFont::setColor(SDL_Color color) {
    this->color = color;
    return getSurface();
}

SDL_Surface *TTFont::setSize(int newSize) {
    TTF_CloseFont(font);
    this->size = newSize;
    font = TTF_OpenFont(path.c_str(), newSize);
    return getSurface();
}

SDL_Surface *TTFont::setPath(const string &path) {
    TTF_CloseFont(font);
    this->path = path;
    font = TTF_OpenFont(path.c_str(), size);
    return getSurface();
}

int TTFont::getSize() const {
    return size;
}

SDL_Color TTFont::getColour() const {
    return color;
}
string TTFont::getPath() const {
    return path;
}
