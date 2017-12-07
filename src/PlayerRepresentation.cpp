//
// Created by Cedric De Schepper on 6/12/17.
//

#include "PlayerRepresentation.h"
#include "Transformation.h"

#include <iostream>
namespace view{


    PlayerRepresentation::PlayerRepresentation(const sf::Texture* texture,
                                               const std::weak_ptr<const model::Entity> &weak_entity) : EntityRepresentation(
            texture, weak_entity){}

    void PlayerRepresentation::draw(std::shared_ptr<sf::RenderWindow> &window) {
        if(to_be_moved){
            sf::Vector2f position = utils::Transformation::get_instance().co_to_pixels(weak_entity.lock(), window);
            EntityRepresentation::setPosition(position);
        }
        window->draw(*this);
        for(auto &sprite : lives){
            window->draw(*sprite);
        }
    }

    void PlayerRepresentation::add_live(std::unique_ptr<sf::Sprite> &live) {
        lives.push_back(std::move(live));
    }
}
