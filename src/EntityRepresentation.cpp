//
// Created by Cedric De Schepper on 15/11/17.
//

#include "EntityRepresentation.h"
#include "Transformation.h"
#include <SFML/Graphics.hpp>

#include <iostream>

namespace view{
    void EntityRepresentation::draw(std::shared_ptr<sf::RenderWindow> window) {
        //if (!entity->is_changed()) return;

        sf::Vector2f position = Transformation::get_instance().co_to_pixels(weak_entity.lock(), window);
        this->setPosition(position);
        window->draw(*this);
    }

    EntityRepresentation::EntityRepresentation(const sf::Texture &texture, const std::weak_ptr<const model::Entity> &weak_entity)
            : Sprite(texture), weak_entity(weak_entity) {
    }


    void EntityRepresentation::scale_representation_to_entity(const sf::Vector2u& window_size) {
        std::shared_ptr<const model::Entity> entity = weak_entity.lock();
        float x_scale = (entity->get_length() * window_size.x) / ((entity->get_max_x_position() * 2) * this->getGlobalBounds().width);
        float y_scale = (entity->get_height() * window_size.y) / ((entity->get_max_y_position() * 2) * this->getGlobalBounds().height);

        this->scale(x_scale, y_scale);
    }
}