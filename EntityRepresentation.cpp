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

        sf::Vector2f position = Transformation::get_instance().co_to_pixels(entity, window);
        EntityRepresentation::setPosition(position);
        window->draw(*this);
    }

    EntityRepresentation::EntityRepresentation(const sf::Texture &texture, const std::shared_ptr<const Entity> &entity)
            : Sprite(texture), entity(entity) {}
}