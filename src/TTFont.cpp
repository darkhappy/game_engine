/// @file TTFont.cpp
/// @brief Contains the implementation of the TTFont class in TTFont.h
/// @author Jean-Philippe (me\@darkh.app)

#include "TTFont.h"

TTFont::TTFont(const string &path, const int &size, const string &text, const SDL_Color &color) {
    this->color = color;
    this->text = text;
    this->size = size;
    this->path = path;
    font = TTF_OpenFont(path.c_str(), size);
    surface = generateSurface();
}

TTFont::~TTFont() {
    SDL_FreeSurface(surface);
    TTF_CloseFont(font);
}

SDL_Surface *TTFont::generateSurface() {
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

SDL_Surface *TTFont::getSurface() {
    return surface;
}

SDL_Surface *TTFont::setText(const std::string &newText) {
    this->text = newText;
    return generateSurface();
}

SDL_Surface *TTFont::setColor(const SDL_Color &newColor) {
    this->color = newColor;
    return generateSurface();
}

SDL_Surface *TTFont::setSize(const int &newSize) {
    TTF_CloseFont(font);
    this->size = newSize;
    font = TTF_OpenFont(path.c_str(), newSize);
    return generateSurface();
}

SDL_Surface *TTFont::setPath(const string &newPath) {
    TTF_CloseFont(font);
    this->path = newPath;
    font = TTF_OpenFont(newPath.c_str(), size);
    return generateSurface();
}

const int &TTFont::getSize() const {
    return size;
}

const SDL_Color &TTFont::getColor() const {
    return color;
}

const string &TTFont::getPath() const {
    return path;
}
const string &TTFont::getText() const {
    return text;
}
