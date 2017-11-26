//
// Created by Cedric De Schepper on 14/11/17.
//

#ifndef GRADIUS_STOPWATCH_H
#define GRADIUS_STOPWATCH_H

#include <SFML/System/Clock.hpp>
#include <chrono>

class Stopwatch {

private:
    Stopwatch();

    std::chrono::high_resolution_clock::time_point start;

    double frame_time = 0.0;

public:
    static Stopwatch& get_instance();

    Stopwatch(const Stopwatch& other) = delete;

    Stopwatch& operator=(const Stopwatch& other) = delete;

    double getFrame_time() const;

    void reset();

};


#endif //GRADIUS_STOPWATCH_H
