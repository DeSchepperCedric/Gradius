
#include "Stopwatch.h"
#include <iostream>

namespace utils {

    Stopwatch::Stopwatch() {
        start = std::chrono::high_resolution_clock::now();
    }

    void Stopwatch::reset() {
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> time = end - start;

        frame_time = time.count();
        start = end;
    }

    float Stopwatch::get_frame_time() const {
        return frame_time;
    }
}

