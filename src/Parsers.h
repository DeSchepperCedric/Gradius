

#ifndef GRADIUS_PARSERS_H
#define GRADIUS_PARSERS_H

#include <memory>
#include "Entity.h"
#include "PlayerShip.h"
#include "Model.h"

#include "json.hpp"
#include "View.h"

using json = nlohmann::json ;

namespace parsers {

    /**
     * @brief
     * @param j json used to get data
     * @return model of MVC for the game
     */
    model::PlayerShip::Shared parse_player(const json& j);

    model::Level::Shared parse_level(const std::string& file_name);

    void parse_model(const json &j, model::Model::Shared& model);

    void parse_view(const json& j, view::View::Shared& view);
}

#endif //GRADIUS_PARSERS_H
