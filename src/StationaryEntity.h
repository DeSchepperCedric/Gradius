//
// Created by Cedric De Schepper on 13/11/17.
//

#ifndef GRADIUS_STATIONARYENTITY_H
#define GRADIUS_STATIONARYENTITY_H

#include "Entity.h"

namespace model {
    class StationaryEntity : public Entity {

    public:

        StationaryEntity(float length, float height, float x_position, float y_position);
    };

}


#endif //GRADIUS_STATIONARYENTITY_H
