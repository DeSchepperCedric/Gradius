//
// Created by Cedric De Schepper on 14/11/17.
//

#ifndef GRADIUS_STOPWATCH_H
#define GRADIUS_STOPWATCH_H


#include <time.h>

class Stopwatch {
private:
    Stopwatch();

    clock_t tick;


public:
    static Stopwatch& get_instance();


    Stopwatch(const Stopwatch& other) = delete;

    Stopwatch& operator=(const Stopwatch& other) = delete;

    clock_t get_tick() const;

};


#endif //GRADIUS_STOPWATCH_H
