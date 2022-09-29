//
// Created by Jean-Philippe on 2022-09-27.
//

#ifndef GAME_ENGINE_SCREENSAVER_H
#define GAME_ENGINE_SCREENSAVER_H


#include <vector>
#include "GLContext.h"
#include "Texture.h"
#include "TTFont.h"

using std::vector;

enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Screensaver {
private:
    GLContext *context; ///< The context
    vector<Texture*> *textures; ///< The textures
    Texture *current; ///< The current texture
    TTFont *font; ///< The font
    double x; ///< The x position of the screensaver
    double y; ///< The y position of the screensaver
    double width; ///< The width of the screensaver
    double height; ///< The height of the screensaver
    double verticalSpeed; ///< The vertical speed of the screensaver
    double horizontalSpeed; ///< The horizontal speed of the screensaver
    Direction verticalDirection; ///< The vertical direction
    Direction horizontalDirection; ///< The horizontal direction

public:
    Screensaver(GLContext *context, vector<Texture*> *textures, TTFont *font = nullptr, double x = 0, double y = 0, double width = 50,
                double height = 50, double verticalSpeed = 1, double horizontalSpeed = 1);

    Screensaver(GLContext *context, Texture *texture, TTFont *font = nullptr, double x = 0, double y = 0, double width = 50, double height = 50,
                double verticalSpeed = 1, double horizontalSpeed = 1);

    void draw();

    void swapHorizontalDirection();

    void swapVerticalDirection();

    void swapTexture();

    void update();
};

#endif //GAME_ENGINE_SCREENSAVER_H
