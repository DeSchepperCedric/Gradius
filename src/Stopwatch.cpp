//
// Created by Cedric De Schepper on 14/11/17.
//

#include "Stopwatch.h"
#include <iostream>

Stopwatch::Stopwatch() {
    clock = sf::Clock();
    //start = std::chrono::high_resolution_clock::now();
}

Stopwatch& Stopwatch::get_instance() {
    static Stopwatch s;
    return s;
}

float Stopwatch::get_time() const {
    return clock.getElapsedTime().asSeconds();
}

void Stopwatch::reset() {
    clock.restart();
}

