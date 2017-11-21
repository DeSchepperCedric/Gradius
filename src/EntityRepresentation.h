//
// Created by Cedric De Schepper on 15/11/17.
//

#ifndef GRADIUS_ENTITYREPRESENTATION_H
#define GRADIUS_ENTITYREPRESENTATION_H

#include <memory>
#include "Entity.h"
#include <SFML/Graphics.hpp>

namespace view {

    class EntityRepresentation : public sf::Sprite {
        friend class View;

    private:
        std::shared_ptr<const model::Entity> entity;
    public:
        typedef std::shared_ptr<EntityRepresentation> Shared;

        EntityRepresentation(const sf::Texture &texture, const std::shared_ptr<const model::Entity> &entity);

        void draw(std::shared_ptr<sf::RenderWindow> window);

        void scale_representation_to_entity(const sf::Vector2u& window_size);
    };

}


#endif //GRADIUS_ENTITYREPRESENTATION_H
