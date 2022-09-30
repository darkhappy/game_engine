//
// Created by Jean-Philippe on 2022-09-27.
//

#ifndef GAME_ENGINE_SCREENSAVER_H
#define GAME_ENGINE_SCREENSAVER_H

#include "GLContext.h"
#include "Texture.h"
#include "TTFont.h"

class Screensaver {
private:
    GLContext *context; ///< The context
    Texture *texture; ///< The texture texture
    TTFont *font; ///< The font

public:
    double x; ///< The x position of the screensaver
    double y; ///< The y position of the screensaver
    double width; ///< The width of the screensaver
    double height; ///< The height of the screensaver
    double verticalSpeed; ///< The vertical speed of the screensaver
    double horizontalSpeed; ///< The horizontal speed of the screensaver

    Screensaver(GLContext *context, Texture *texture, TTFont *font, double x = 0, double y = 0, double width = 100,
                double height = 100, double horizontalSpeed = 1, double verticalSpeed = 1);

    void draw();

    void swapHorizontalDirection();

    void swapVerticalDirection();

    void update();
};

#endif //GAME_ENGINE_SCREENSAVER_H
