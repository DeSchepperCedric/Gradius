//
// Created by Cedric De Schepper on 6/12/17.
//

#include "PlayerRepresentation.h"
#include "Transformation.h"

#include <iostream>
namespace view{


    PlayerRepresentation::PlayerRepresentation(const sf::Texture *texture,
                                               const std::weak_ptr<const model::Entity> &weak_entity,
                                               const std::vector<sf::Sprite> &lives) : EntityRepresentation(
            texture, weak_entity), lives(lives) {}

    void PlayerRepresentation::draw(std::shared_ptr<sf::RenderWindow> &window) {
        if(to_be_moved){
            sf::Vector2f position = utils::Transformation::get_instance().co_to_pixels(weak_entity.lock(), window);
            EntityRepresentation::setPosition(position);
        }
        window->draw(*this);

        for(auto &sprite : lives){
            sprite.setColor(sf::Color::White);
            window->draw(sprite);
        }
    }
}
