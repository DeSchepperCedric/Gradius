//
// Created by Cedric De Schepper on 13/11/17.
//

#ifndef GRADIUS_ENTITY_H
#define GRADIUS_ENTITY_H

namespace model{

    struct Co {
        float x;
        float y;
    };

    struct Hitbox {
        Co upper_left;
        Co lower_left;

        Co upper_right;
        Co lower_right;
    };

class Entity{
protected:
    float length;
    float height;

    // coordinates of most upper left corner
    float x_position;
    float y_position;

    float max_x_position = 4;
    float min_x_position = -4;

    float max_y_position = 3;
    float min_y_position = -3;

    bool changed = false;
public:
    Entity(float length, float height, float x_position, float y_position);

    const float get_length() const;

    const float get_height() const;

    float get_x_position() const;

    float get_y_position() const;

    float get_max_x_position() const;

    float get_min_x_position() const;

    float get_max_y_position() const;

    float get_min_y_position() const;

    bool is_changed() const;

    void set_changed(bool changed);

    Hitbox get_hitbox();


};

}


#endif //GRADIUS_ENTITY_H
