/// @file Texture.h
/// @brief Contains the declaration of the Texture class
/// @author Jean-Philippe (me\@darkh.app)

#ifndef GAME_ENGINE_TEXTURE_H
#define GAME_ENGINE_TEXTURE_H

#include <SDL2/SDL_image.h>
#include <SDL2/SDL_opengl.h>
#include <string>

using std::string;

/// @class Texture
/// @brief A class that represents a texture
class Texture {
private:
    GLuint textureID{};///< The texture ID used by OpenGL

    int width{}; ///< The width of the texture.
    int height{};///< The height of the texture.
public:
    /// @param path The path to the texture.
    explicit Texture(const string &path);

    /// @param surface The surface to use to generate the texture.
    /// @param isFont If the surface is a font (else it displays weirdly on macOS).
    /// @note The surface will be freed after the texture is generated.
    explicit Texture(const SDL_Surface &surface, bool isFont = false);

    ~Texture();

    /// @brief Binds the texture to OpenGL.
    void bind() const;

    /// @brief Gets the texture ID.
    /// @return The texture ID.
    [[nodiscard]] const GLuint &getTextureID() const;

    /// @brief Gets the width of the texture.
    /// @return The width of the texture.
    [[nodiscard]] const int &getWidth() const;

    /// @brief Gets the height of the texture.
    /// @return The height of the texture.
    [[nodiscard]] const int &getHeight() const;
};

#endif//GAME_ENGINE_TEXTURE_H