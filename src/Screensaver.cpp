//
// Created by Jean-Philippe on 2022-09-27.
//

#include "Screensaver.h"

Screensaver::Screensaver(GLContext *context, Texture *texture, Texture *font, double x, double y, double width,
                         double height, double horizontalSpeed, double verticalSpeed) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->verticalSpeed = verticalSpeed;
    this->horizontalSpeed = horizontalSpeed;
    this->context = context;
    this->texture = texture;
    this->text = font;
}

void Screensaver::swapHorizontalDirection() {
    horizontalSpeed *= -1;
}

void Screensaver::swapVerticalDirection() {
    verticalSpeed *= -1;
}

void Screensaver::draw() {
    texture->bind();
    GLContext::drawRectangle(Vector3d(x, y), Vector3d(width, height));

    text->bind();
    GLContext::drawRectangle(Vector3d(x, y - text->getHeight()), Vector3d(text->getWidth(), text->getHeight()));
}

void Screensaver::update() {
    // Detect vertical collisions
    if (y <= 0) {
        y = 0;
        swapVerticalDirection();
    } else if (y + height >= context->getHeight()) {
        y = context->getHeight() - height;
        swapVerticalDirection();
    } else if (y - text->getHeight() <= 0) {
        y = text->getHeight();
        swapVerticalDirection();
    }

    y += verticalSpeed;

    // Detect horizontal collisions
    if (x <= 0) {
        x = 0;
        swapHorizontalDirection();
    } else if (x + text->getWidth() >= context->getWidth()) {
        x = context->getWidth() - text->getWidth();
        swapHorizontalDirection();
    } else if (x + width >= context->getWidth()) {
        x = context->getWidth() - width;
        swapHorizontalDirection();
    }

    x += horizontalSpeed;
}
