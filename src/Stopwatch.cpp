//
// Created by Cedric De Schepper on 14/11/17.
//

#include "Stopwatch.h"
#include <iostream>

Stopwatch::Stopwatch() {
    start = std::chrono::high_resolution_clock::now();
}

Stopwatch& Stopwatch::get_instance() {
    static Stopwatch s;
    return s;
}


void Stopwatch::reset() {
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time = end - start;

    frame_time = time.count();
    start = end;
}

double Stopwatch::getFrame_time() const {
    return frame_time;
}

