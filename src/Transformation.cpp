
#include "Transformation.h"

#include <cmath>
#include <iostream>
namespace utils {



    sf::Vector2f Transformation::co_to_pixels(std::shared_ptr<const model::Entity> entity,
                                              const std::unique_ptr<sf::RenderWindow>& window) {
        float co_x_max = entity->get_max_x_position();
        float co_y_max = entity->get_max_y_position();

        float co_x = entity->get_x_position();
        float co_y = entity->get_y_position();

        int pixel_x_max = window->getSize().x;
        int pixel_y_max = window->getSize().y;

        float pixel_x;
        float pixel_y;

        if (co_x >= 0) {
            pixel_x = (int) (roundf((co_x / co_x_max) * (pixel_x_max / 2) + (pixel_x_max / 2)));
        } else {
            pixel_x = (int) roundf(((co_x + co_x_max) / co_x_max) * (pixel_x_max / 2));
        }

        if (co_y >= 0) {
            pixel_y = (int) roundf((pixel_y_max / 2) - (co_y / co_y_max) * (pixel_y_max / 2));
        } else {
            pixel_y = (int) roundf((pixel_y_max / 2) + (-co_y / co_y_max) * (pixel_y_max / 2));
        }
        return {pixel_x, pixel_y};
    }
}

