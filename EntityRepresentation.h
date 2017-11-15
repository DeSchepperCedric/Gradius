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
        std::shared_ptr<const Entity> entity;
    public:
        typedef std::shared_ptr<EntityRepresentation> Shared;

        EntityRepresentation(const sf::Texture &texture, const std::shared_ptr<const Entity> &entity);

        void draw(std::shared_ptr<sf::RenderWindow> window);


    };

}


#endif //GRADIUS_ENTITYREPRESENTATION_H
