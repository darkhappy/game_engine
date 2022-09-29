//
// Created by Jean-Philippe on 2022-09-28.
//

#include "Observable.h"

template <typename T>
void Observable<T>::subscribe(const Observer<T> &observer) {
    observers.push_back(observer);
}

template <typename T>
void Observable<T>::unsubscribe(const Observer<T> &observer) {
    observers.remove(observer);
}

template<typename T>
void Observable<T>::notify(const T &data) {
    for (auto observer : observers) {
        observer->notification(data);
    }
}

