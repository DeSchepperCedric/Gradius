//
// Created by Cedric De Schepper on 13/11/17.
//

#ifndef GRADIUS_ENTITY_H
#define GRADIUS_ENTITY_H

namespace model{

class Entity{
protected:
    double length;
    double height;

    // coordinates of most upper left corner
    double x_position;
    double y_position;

    double max_x_position = 4;
    double min_x_position = -4;

    double max_y_position = 3;
    double min_y_position = -3;

    bool changed = false;
public:
    Entity(double length, double height, double x_position, double y_position);

    const double get_length() const;

    const double get_height() const;

    double get_x_position() const;

    double get_y_position() const;

    double get_max_x_position() const;

    double get_min_x_position() const;

    double get_max_y_position() const;

    double get_min_y_position() const;

    bool is_changed() const;

    void set_changed(bool changed);


};

}


#endif //GRADIUS_ENTITY_H
