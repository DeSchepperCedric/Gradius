
/**@class model::Wave
 *
 * @brief class to represent waves of enemies to spawn in levels
 *
 * @author Cedric De Schepper
 */

#ifndef GRADIUS_WAVE_H
#define GRADIUS_WAVE_H

#include "Entity.h"

namespace model {

    class Wave {
    private:
        double time = 0.0;
        // shared because model needs shared entities
        std::vector<Entity::Shared> entities = {};

    public:
        typedef std::shared_ptr<Wave> Shared;
        /**
         * @brief default constructor
         */
        Wave() = default;

        /**
         * @brief simple getter: get time before wave should be deployed
         * @return time
         */
        double get_time() const;

        /**
         * simple setter: set time before wave should be deployed
         * @param time
         */
        void set_time(double time);

        void add_entity(const Entity::Shared& entity);

        const std::vector<Entity::Shared> &get_entities() const;

    };
}


#endif //GRADIUS_WAVE_H
