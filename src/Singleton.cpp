/// @file Singleton.cpp
/// @brief Contains the implementation of the Singleton class in Singleton.h
/// @author Jean-Philippe (me\@darkh.app)

#include "Singleton.h"
#include "Application.h"

template<typename T>
T Singleton<T>::instance;

template<typename T>
T &Singleton<T>::getInstance() {
    return instance;
}

template class Singleton<Application>;
