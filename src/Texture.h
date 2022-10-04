//
// Created by Jean-Philippe on 2022-09-27.
//

#ifndef GAME_ENGINE_TEXTURE_H
#define GAME_ENGINE_TEXTURE_H

#include <SDL2/SDL_image.h>
#include <SDL2/SDL_opengl.h>

class Texture {
private:
    GLuint textureID{};///< The texture ID

    int width{};///< The width
    int height{};///< The height
public:
    explicit Texture(const char *path);

    explicit Texture(const SDL_Surface &surface, bool isFont = false);

    ~Texture();

    void bind() const;

    [[nodiscard]] GLuint getTextureID() const;

    [[nodiscard]] int getWidth() const;

    [[nodiscard]] int getHeight() const;
};

#endif//GAME_ENGINE_TEXTURE_H