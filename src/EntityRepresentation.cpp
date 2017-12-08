

#include "EntityRepresentation.h"
#include "Transformation.h"
#include <SFML/Graphics.hpp>

#include <iostream>

namespace view{
    void EntityRepresentation::draw(std::unique_ptr<sf::RenderWindow>& window) {

        // if entity has been moved, move representation to correct position
        if(to_be_moved){
            sf::Vector2f position = utils::Transformation::get_instance().co_to_pixels(weak_entity.lock(), window);
            EntityRepresentation::setPosition(position);
        }

        // draw the representation on screen
        window->draw(*this);
    }

    EntityRepresentation::EntityRepresentation(const sf::Texture* texture,
                                               const std::weak_ptr<const model::Entity> &weak_entity) :
            Sprite(*texture),
            weak_entity(weak_entity) {}


    void EntityRepresentation::scale_representation_to_entity(const sf::Vector2u& window_size) {
        // scale the representation relative to its original image file
        std::shared_ptr<const model::Entity> entity = weak_entity.lock();
        float x_scale = (entity->get_length() * window_size.x) / ((entity->get_max_x_position() * 2) * this->getGlobalBounds().width);
        float y_scale = (entity->get_height() * window_size.y) / ((entity->get_max_y_position() * 2) * this->getGlobalBounds().height);

        EntityRepresentation::scale(x_scale, y_scale);
    }

    void EntityRepresentation::on_notification(const observer::Notification& notification) {
        if(auto movement = dynamic_cast<const observer::MovementNotification*>(&notification)){
            // can't move yet because movement distance is relative to window size
            EntityRepresentation::to_be_moved = true;
        }

    }

    const std::weak_ptr<const model::Entity> &EntityRepresentation::get_weak_entity() const {
        return weak_entity;
    }


}