//
// Created by Jean-Philippe on 2022-09-28.
//

#ifndef GAME_ENGINE_OBSERVER_H
#define GAME_ENGINE_OBSERVER_H

template <typename T>
class Observer {
public:
    virtual void notification(T data) = 0;
};

#endif //GAME_ENGINE_OBSERVER_H
