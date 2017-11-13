//
// Created by Cedric De Schepper on 13/11/17.
//

#ifndef GRADIUS_ENTITY_H
#define GRADIUS_ENTITY_H


class Entity {
protected:
    const int length;
    const int height;

    int x_position;
    int y_position;

    int max_x_position = 4;
    int min_x_position = -4;

    int max_y_position = 3;
    int min_y_position = -3;
public:
    Entity(int length, int height, int x_position, int y_position);




};


#endif //GRADIUS_ENTITY_H
