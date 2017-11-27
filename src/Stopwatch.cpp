//
// Created by Cedric De Schepper on 14/11/17.
//

#include "Stopwatch.h"
#include <iostream>

namespace utils {

    Stopwatch::Stopwatch() {
        start = std::chrono::high_resolution_clock::now();
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
}

