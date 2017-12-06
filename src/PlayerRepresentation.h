

#ifndef GRADIUS_PLAYERREPRESENTATION_H
#define GRADIUS_PLAYERREPRESENTATION_H

#include "EntityRepresentation.h"

namespace view {

    class PlayerRepresentation : public EntityRepresentation {
    private:
        std::vector<sf::Sprite> lives;

    public:
        typedef std::shared_ptr<PlayerRepresentation> Shared;

        PlayerRepresentation(const sf::Texture *texture, const std::weak_ptr<const model::Entity> &weak_entity,
                             const std::vector<sf::Sprite> &lives);

        void draw(std::shared_ptr<sf::RenderWindow>& window) override;


    };
}


#endif //GRADIUS_PLAYERREPRESENTATION_H
