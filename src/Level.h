/**@class model::Level
 *
 * @brief levels class that the player has to face in the game
 *
 * @author Cedric De Schepper
 */

#ifndef GRADIUS_LEVEL_H
#define GRADIUS_LEVEL_H

#include "Entity.h"
#include "Wave.h"

#include <vector>
#include <queue>
#include <memory>

namespace model {

    class Level {
    private:
        std::queue<Wave::Shared> waves = {};

    public:
        typedef std::unique_ptr<Level> Unique;
        typedef std::shared_ptr<Level> Shared;

        Level() = default;

        /**
         * @brief add a wave to the level
         * @param wave wave to be added
         */
        void add_wave(const Wave::Shared& wave);

        /**
         * @brief deploy a wave : give the first wave in the queue
         * @return
         */
        const Wave::Shared& deploy_wave();

        /**
         * @brief checks if the level is done
         * @return level done
         */
        bool level_done() const;

        /**
         * @brief remove a wave when it was time to deploy it
         */
        void pop_wave();
    };

}


#endif //GRADIUS_LEVEL_H
