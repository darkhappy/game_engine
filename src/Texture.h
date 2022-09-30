//
// Created by Jean-Philippe on 2022-09-27.
//

#ifndef GAME_ENGINE_TEXTURE_H
#define GAME_ENGINE_TEXTURE_H

#include <SDL2/SDL_opengl.h>

class Texture {
///< The texture ID
protected:
    GLuint textureID{};
public:
    explicit Texture(const char *path);

    ~Texture();

    void bind() const;

    static void unbind();

    [[nodiscard]] GLuint getTextureID() const;
};

#endif //GAME_ENGINE_TEXTURE_H