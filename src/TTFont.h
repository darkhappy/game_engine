//
// Created by Jean-Philippe on 2022-09-28.
//

#ifndef GAME_ENGINE_TTFONT_H
#define GAME_ENGINE_TTFONT_H

#include <SDL2/SDL_ttf.h>
#include <string>
#include "GLContext.h"
#include "Texture.h"

class TTFont : public Texture {
private:
    TTF_Font *font; ///< The font
    SDL_Color color; ///< The color
    std::string text; ///< The text
    int size; ///< The size

    int width; ///< The width
    int height; ///< The height

    void load();
public:
    TTFont(const char *path, int size, const std::string &text, SDL_Color color = {255, 255, 255, 255});

    ~TTFont();

    void setText(const std::string &text);

    void setColor(SDL_Color color);

    void setSize(int newSize);

    [[nodiscard]] int getWidth() const;

    [[nodiscard]] int getHeight() const;

    void draw(int x, int y);
};


#endif //GAME_ENGINE_TTFONT_H
