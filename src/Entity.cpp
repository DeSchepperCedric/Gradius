//
// Created by Cedric De Schepper on 13/11/17.
//

#include "Entity.h"


Entity::Entity(double length, double height, double x_position, double y_position) : length(length), height(height),
                                                                                     x_position(x_position),
                                                                                     y_position(y_position) {
    /// exceptions to be added!!
}


const double Entity::get_length() const {
    return length;
}

const double Entity::get_height() const {
    return height;
}

double Entity::get_x_position() const {
    return x_position;
}

double Entity::get_y_position() const {
    return y_position;
}

double Entity::get_max_x_position() const {
    return max_x_position;
}

double Entity::get_min_x_position() const {
    return min_x_position;
}

double Entity::get_max_y_position() const {
    return max_y_position;
}

double Entity::get_min_y_position() const {
    return min_y_position;
}

bool Entity::is_changed() const {
    return changed;
}

void Entity::set_changed(bool changed) {
    Entity::changed = changed;
}
