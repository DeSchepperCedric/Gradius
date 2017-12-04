/**
 * @class utils::StopWatch
 *
 * @brief Stopwatch Singleton class to calculate time per frame
 *
 * @author Cedric De Schepper
 *
 */

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

        /**
         * @brief simple getter : gets time per frame
         * @return frame_time
         */
        float get_frame_time() const;

        /**
         * @brief reset chrono back to 0;
         */
        void reset();

    };

}


#endif //GRADIUS_STOPWATCH_H
