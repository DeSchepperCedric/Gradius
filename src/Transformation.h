/**
 * @class utils::Transformation
 *
 * @brief Transformation Singleton class to convert coordinates to pixels
 *
 * @author Cedric De Schepper
 *
 */

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
        /**
         * @brief convert coordinates to pixels
         * @param entity entity used to get coordinates
         * @param window window used for window size
         * @return
         */
        sf::Vector2f co_to_pixels(std::shared_ptr<const model::Entity> entity, const std::unique_ptr<sf::RenderWindow>& window);
    };
}


#endif //GRADIUS_TRANSFORMATION_H
