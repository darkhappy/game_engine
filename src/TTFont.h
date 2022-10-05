/// @file TTFont.h
/// @brief Contains the declaration of the TTFont class
/// @author Jean-Philippe (me\@darkh.app)

#ifndef GAME_ENGINE_TTFONT_H
#define GAME_ENGINE_TTFONT_H

#include "Texture.h"
#include <SDL2/SDL_ttf.h>
#include <string>

using std::string;

/// @class TTFont
/// @brief A class that represents a TrueType font
class TTFont {
private:
    TTF_Font *font;        ///< The font used.
    SDL_Color color{};       ///< The colour of the font.
    string text;           ///< The text to display.
    string path;           ///< The path to the font.
    SDL_Surface *surface{};///< The surface used to render the text.

    int size;///< The point size

    /// @brief Generates the surface.
    /// @return The surface generated.
    SDL_Surface *generateSurface();
public:
    /// @param path The path to the font.
    /// @param size The point size.
    /// @param text The text to display.
    /// @param color The colour of the font.
    TTFont(const string &path, const int &size, const string &text = " ", const SDL_Color &color = {255, 255, 255, 255});

    ~TTFont();

    /// @brief Gets the surface of the text.
    /// @return The surface used to render the text.
    SDL_Surface *getSurface();

    /// @brief Gets the path to the font.
    /// @return The path to the font.
    [[nodiscard]] const string &getPath() const;

    /// @brief Gets the point size of the font.
    /// @return The point size of the font.
    [[nodiscard]] const int &getSize() const;

    /// @brief Gets the text to display.
    /// @return The text to display.
    [[nodiscard]] const string &getText() const;

    /// @brief Gets the colour of the font.
    /// @return The colour of the font.
    [[nodiscard]] const SDL_Color &getColor() const;

    /// @brief Sets the new path to the font.
    /// @param newPath The new path to the font.
    /// @return The newly generated surface used to render the text.
    SDL_Surface *setPath(const string &newPath);

    /// @brief Sets the point size of the font.
    /// @param newSize The point size of the font.
    /// @return The newly generated surface used to render the text.
    SDL_Surface *setSize(const int &newSize);

    /// @brief Sets the newText to display.
    /// @param newText The newText to display.
    /// @return The newly generated surface used to render the newText.
    SDL_Surface *setText(const string &newText);

    /// @brief Sets the colour of the font.
    /// @param newColor The colour of the font.
    /// @return The newly generated surface used to render the text.
    SDL_Surface *setColor(const SDL_Color &newColor);
};


#endif//GAME_ENGINE_TTFONT_H
