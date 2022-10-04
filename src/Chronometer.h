/// @file Chronometer.h
/// @brief Contains the declaration of the Chronometer class
/// @author Jean-Philippe (me\@darkh.app)

#ifndef GAME_ENGINE_CHRONOMETER_H
#define GAME_ENGINE_CHRONOMETER_H

#include <chrono>

using std::chrono::steady_clock;
using std::chrono::duration;
using std::chrono::duration_cast;
using std::chrono::nanoseconds;

/// @brief Represents a chronometer that can be used to measure time.
class Chronometer {
private:
    steady_clock::time_point start; ///< The time point at which the chronometer was started.
public:
    /// @brief Creates a new chronometer and starts it.
    Chronometer();

    /// @brief Restarts the chronometer.
    void reset();

    /// @brief Gets the elapsed time since the chronometer was started.
    /// @return The elapsed time since the chronometer was started.
    [[nodiscard]] double getDelta() const;
};


#endif //GAME_ENGINE_CHRONOMETER_H
