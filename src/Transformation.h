//
// Created by Cedric De Schepper on 15/11/17.
//

#ifndef GRADIUS_TRANSFORMATION_H
#define GRADIUS_TRANSFORMATION_H

#include <utility>
#include <memory>
#include "Entity.h"
#include <SFML/Graphics.hpp>

#include "Singleton.h"

namespace utils{
    class Transformation : public Singleton<Transformation> {
        friend class Singleton<Transformation>;
    private:
        Transformation() = default;

    public:

        sf::Vector2f co_to_pixels(std::shared_ptr<const model::Entity> entity, std::shared_ptr<const sf::RenderWindow> window);
    };
}


#endif //GRADIUS_TRANSFORMATION_H
