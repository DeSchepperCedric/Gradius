
#ifndef GRADIUS_UTILITIES_H
#define GRADIUS_UTILITIES_H

namespace model{

    struct Co {
        float x;
        float y;
    };

    struct Hitbox {
        float max_x;
        float max_y;

        float min_x;
        float min_y;
    };

    struct Moves{
        bool move_up = false;
        bool move_down = false;
        bool move_left = false;
        bool move_right = false;
    };
}

#endif //GRADIUS_UTILITIES_H

