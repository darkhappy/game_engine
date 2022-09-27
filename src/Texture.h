//
// Created by Jean-Philippe on 2022-09-27.
//

#ifndef GAME_ENGINE_TEXTURE_H
#define GAME_ENGINE_TEXTURE_H

#include <SDL2/SDL_image.h>
#include <SDL2/SDL_opengl.h>

class Texture {
private:
    GLuint textureID; ///< The texture ID
public:
    explicit Texture(const char *path);

    ~Texture();

    void bind() const;

    static void unbind();

    [[nodiscard]] unsigned int getTextureID() const;
};

#endif //GAME_ENGINE_TEXTURE_H