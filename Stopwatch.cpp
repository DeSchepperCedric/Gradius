//
// Created by Cedric De Schepper on 14/11/17.
//

#include "Stopwatch.h"
#include <iostream>

Stopwatch::Stopwatch() {
    clock_t t = clock();
    t = t - clock();

    Stopwatch::tick = t;
}

Stopwatch& Stopwatch::get_instance() {
    static Stopwatch s;
    return s;
}

clock_t Stopwatch::get_tick() const {
    return tick;
}

