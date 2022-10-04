//
// Created by Jean-Philippe on 2022-09-28.
//

#ifndef GAME_ENGINE_TTFONT_H
#define GAME_ENGINE_TTFONT_H

#include <SDL2/SDL_ttf.h>
#include <string>
#include "Texture.h"

using std::string;

class TTFont {
private:
    TTF_Font *font; ///< The text
    SDL_Color color{}; ///< The color
    string text; ///< The text
    string path; ///< Path of the text
    SDL_Surface *surface; ///< The surface

    int size;
public:
    TTFont(const char *path, int size, const string &text = " ", SDL_Color color = {255, 255, 255, 255});

    ~TTFont();

    SDL_Surface *getSurface();

    SDL_Surface *setText(const string &text);

    SDL_Surface *setColor(SDL_Color color);

    SDL_Surface *setSize(int newSize);

    SDL_Surface *setPath(const string &path);

    [[nodiscard]] SDL_Color getColour() const;

    [[nodiscard]] int getSize() const;

    [[nodiscard]] string getPath() const;
};


#endif //GAME_ENGINE_TTFONT_H
