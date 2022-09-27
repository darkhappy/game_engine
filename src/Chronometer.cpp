//
// Created by Jean-Philippe on 2022-09-26.
//

#include "Chronometer.h"

Chronometer::Chronometer() {
    this->start = steady_clock::now();
}

void Chronometer::startChronometer() {
    this->start = steady_clock::now();
}

double Chronometer::getElapsedTime() {
    return (double) duration_cast<nanoseconds>(steady_clock::now() - this->start).count() / 1000000000.0;
}