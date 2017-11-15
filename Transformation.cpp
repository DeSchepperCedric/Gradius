//
// Created by Cedric De Schepper on 15/11/17.
//

#include "Transformation.h"
#include <cmath>
#include <iostream>

Transformation::Transformation() {}

Transformation& Transformation::get_instance() {
    static Transformation t;
    return t;
}

sf::Vector2f Transformation::co_to_pixels(std::shared_ptr<const Entity> entity, std::shared_ptr<const sf::RenderWindow> window) {
    /// make float for pixels??
    double co_x_max = entity->get_max_x_position();
    double co_y_max = entity->get_max_y_position();

    double co_x = entity->get_x_position();
    double co_y = entity->get_y_position();

    int pixel_x_max = window->getSize().x;
    int pixel_y_max = window->getSize().y;

    float pixel_x;
    float pixel_y;

    double entity_pixel_length = (entity->get_length() / co_x_max) * (pixel_x_max / 2);
    double entity_pixel_height = round((entity->get_height() / co_y_max) * (pixel_y_max / 2) );

    if(co_x >= 0){
        pixel_x = (int) (round((co_x / co_x_max) * (pixel_x_max / 2) + (pixel_x_max / 2))) ;
    }
    else{
        pixel_x = (int) round(((co_x + co_x_max) / co_x_max) * (pixel_x_max / 2));
    }

    if(co_y >= 0){
        pixel_y = (int) round((pixel_y_max/2) - (co_y / co_y_max) * (pixel_y_max / 2));
    }
    else{
        pixel_y = (int) round( (pixel_y_max / 2) + (-co_y / co_y_max) * (pixel_y_max / 2));
    }
    return {pixel_x, pixel_y};
}

