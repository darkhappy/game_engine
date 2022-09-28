//
// Created by Jean-Philippe on 2022-09-27.
//

#include "Screensaver.h"


Screensaver::Screensaver(GLContext *context, vector<Texture *> *textures, double x, double y, double width,
                         double height, double verticalSpeed, double horizontalSpeed) {
    if (textures->empty()) {
        throw std::invalid_argument("The textures vector is empty");
    }

    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->verticalSpeed = verticalSpeed;
    this->horizontalSpeed = horizontalSpeed;
    this->context = context;
    this->textures = textures;
    this->current = textures->at(0);

    verticalDirection = DOWN;
    horizontalDirection = RIGHT;
}

Screensaver::Screensaver(GLContext *context, Texture *texture, double x, double y, double width, double height,
                         double verticalSpeed, double horizontalSpeed) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->verticalSpeed = verticalSpeed;
    this->horizontalSpeed = horizontalSpeed;
    this->context = context;
    this->current = texture;
    this->textures = nullptr;

    verticalDirection = DOWN;
    horizontalDirection = RIGHT;
}

void Screensaver::swapHorizontalDirection() {
    if (horizontalDirection == LEFT) {
        horizontalDirection = RIGHT;
    } else {
        horizontalDirection = LEFT;
    }

    horizontalSpeed *= -1;
}

void Screensaver::swapVerticalDirection() {
    if (verticalDirection == UP) {
        verticalDirection = DOWN;
    } else {
        verticalDirection = UP;
    }

    verticalSpeed *= -1;
}

void Screensaver::swapTexture() {
    if (textures == nullptr || textures->empty() || textures->size() == 1) {
        return;
    }

    // Get the index of the current texture
    int index = 0;

    for (int i = 0; i < textures->size(); i++) {
        if (textures->at(i)->getTextureID() == current->getTextureID()) {
            index = i;
            break;
        }
    }

    // Swap the texture
    if (index == textures->size() - 1) {
        current = textures->at(0);
    } else {
        current = textures->at(index + 1);
    }
}

void Screensaver::draw() {
    current->bind();
    GLContext::drawRectangle(x, y, x + width, y, x, y + height, x + width, y + height);
    Texture::unbind();
}

void Screensaver::update() {
    // Detect vertical collisions
    if (y <= 0) {
        swapVerticalDirection();
        swapTexture();

        y = 0;
    } else if (y + height >= context->getHeight()) {
        swapVerticalDirection();
        swapTexture();

        y = context->getHeight() - height;
    }

    y += verticalSpeed;

    // Detect horizontal collisions
    if (x <= 0) {
        swapHorizontalDirection();
        swapTexture();

        x = 0;
    } else if (x + width >= context->getWidth()) {
        swapHorizontalDirection();
        swapTexture();

        x = context->getWidth() - width;
    }

    x += horizontalSpeed;
}
