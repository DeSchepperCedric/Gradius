//
// Created by Cedric De Schepper on 14/11/17.
//

#ifndef GRADIUS_STOPWATCH_H
#define GRADIUS_STOPWATCH_H

#include <SFML/System/Clock.hpp>

class Stopwatch {
private:
    Stopwatch();

    sf::Clock clock;


public:
    static Stopwatch& get_instance();


    Stopwatch(const Stopwatch& other) = delete;

    Stopwatch& operator=(const Stopwatch& other) = delete;

    float get_time() const;

    void reset();

};


#endif //GRADIUS_STOPWATCH_H
