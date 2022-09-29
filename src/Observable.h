/// @file Observable.h
/// @brief Contains the definition of the Observable class
/// @author Jean-Philippe (me\@darkh.app)

#ifndef GAME_ENGINE_OBSERVABLE_H
#define GAME_ENGINE_OBSERVABLE_H

#include <list>
#include "Observer.h"

using std::list;

/// @class Observable
/// @brief Represents an observable object
/// @tparam T The type of the data to send to the observers
template <typename T>
class Observable {
private:
    list<Observer<T>*> observers; ///< The list of observers
public:
    /// @brief Subscribes an observer to the observable
    /// @param observer The observer to subscribe
    void subscribe(const Observer<T>& observer);

    /// @brief Unsubscribes an observer from the observable
    /// @param observer The observer to unsubscribe
    void unsubscribe(const Observer<T>& observer);

    /// @brief Notifies all the observers
    void notify(const T& data);
};


#endif //GAME_ENGINE_OBSERVABLE_H
