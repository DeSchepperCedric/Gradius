//
// Created by Cedric De Schepper on 14/11/17.
//

#ifndef GRADIUS_STOPWATCH_H
#define GRADIUS_STOPWATCH_H

#include <SFML/System/Clock.hpp>
#include <chrono>

#include "Singleton.h"

namespace utils {

    class Stopwatch : public Singleton<Stopwatch> {
        friend class Singleton<Stopwatch>;
    private:

        std::chrono::high_resolution_clock::time_point start;

        float frame_time = 0.0;

        Stopwatch();

    public:

        float getFrame_time() const;

        void reset();

    };

}


#endif //GRADIUS_STOPWATCH_H
