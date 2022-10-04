//
// Created by Jean-Philippe on 2022-09-28.
//

#ifndef GAME_ENGINE_TTFONT_H
#define GAME_ENGINE_TTFONT_H

#include <SDL2/SDL_ttf.h>
#include <string>
#include "Texture.h"

using std::string;

class TTFont : public Texture {
private:
    TTF_Font *font; ///< The font
    SDL_Color color{}; ///< The color
    string text; ///< The text
    string path; ///< Path of the font

    int size{}; ///< The size
    int width{}; ///< The width
    int height{}; ///< The height

    void load();
public:
    TTFont(const char *path, int size, const string &text = " ", SDL_Color color = {255, 255, 255, 255});

    ~TTFont();

    void setText(const string &text);

    void setColor(SDL_Color color);

    void setSize(int newSize);

    void setPath(const string &path);

    [[nodiscard]] SDL_Color getColour() const;

    [[nodiscard]] int getSize() const;

    [[nodiscard]] int getWidth() const;

    [[nodiscard]] int getHeight() const;

    [[nodiscard]] string getPath() const;
};


#endif //GAME_ENGINE_TTFONT_H
