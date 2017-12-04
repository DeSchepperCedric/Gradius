//
// Created by Cedric De Schepper on 3/12/17.
//

#ifndef GRADIUS_ENEMYSHIP_H
#define GRADIUS_ENEMYSHIP_H

#include "Ship.h"

namespace model {

    class EnemyShip : public Ship {
    public:
        EnemyShip(float length, float height, float x_position, float y_position, float speed, int health, int damage,
                  double time_before_shot);

        const std::string get_name() const override;

        Co get_gun_position() override;

        void update(double time) override;

    };


}


#endif //GRADIUS_ENEMYSHIP_H
