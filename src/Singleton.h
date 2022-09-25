/// @file Singleton.hpp
/// @brief Contains the definition of the Singleton class
/// @author Jean-Philippe (me\@darkh.app)

#ifndef GAME_ENGINE_SINGLETON_H
#define GAME_ENGINE_SINGLETON_H

/// @class Singleton
/// @brief Represents a singleton
/// @tparam T The type of the singleton
template <typename T>
class Singleton {
private:
    static T instance; ///< The instance of the singleton
public:
    /// @brief Gets the instance of the singleton
    /// @return The instance of the singleton
    static T& getInstance();
};

#endif //GAME_ENGINE_SINGLETON_H
