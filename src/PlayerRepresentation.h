

#ifndef GRADIUS_PLAYERREPRESENTATION_H
#define GRADIUS_PLAYERREPRESENTATION_H

#include "EntityRepresentation.h"

namespace view {

    class PlayerRepresentation : public EntityRepresentation {
    private:
        std::vector<std::unique_ptr<sf::Sprite>> lives;

    public:
        typedef std::shared_ptr<PlayerRepresentation> Shared;

        PlayerRepresentation(const sf::Texture *texture, const std::weak_ptr<const model::Entity> &weak_entity);

        void draw(std::unique_ptr<sf::RenderWindow>& window) override;

        void add_live( std::unique_ptr<sf::Sprite>& live);


    };
}


#endif //GRADIUS_PLAYERREPRESENTATION_H
