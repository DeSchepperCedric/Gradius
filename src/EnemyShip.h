/**
 * @class model::EnemyShip
 *
 * @brief EnemyShip entity : enemy ship that can shoot at the player
 *
 * @author Cedric De Schepper
 *
 */

#ifndef GRADIUS_ENEMYSHIP_H
#define GRADIUS_ENEMYSHIP_H

#include "Ship.h"

namespace model {

    class EnemyShip : public Ship {
    public:
        EnemyShip(float length, float height, float x_position, float y_position, float speed, int health, int damage,
                  double time_before_shot);

        /**
         * @brief get name
         * @return "EnemyShip"
         */
        const std::string get_name() const override;

        /**
         * @brief : determines position of its gun
         * @return gun coordinates
         */
        Co get_gun_position() override;

        /**
         * @brief update EnemyShip : update_gun_timer and move
         * @param time
         */
        void update(double time) override;

    };


}


#endif //GRADIUS_ENEMYSHIP_H
