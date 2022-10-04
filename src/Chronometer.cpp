/// @file Chronometer.cpp
/// @brief Contains the implementation of the Chronometer class in Chronometer.h
/// @author Jean-Philippe (me\@darkh.app)

#include "Chronometer.h"

Chronometer::Chronometer() {
    this->start = steady_clock::now();
}

void Chronometer::reset() {
    this->start = steady_clock::now();
}

double Chronometer::getDelta() const {
    return (double) duration_cast<nanoseconds>(steady_clock::now() - this->start).count() / 1000000000.0;
}