/**
 * @brief header file for parsing a json for the game
 *
 * @author Cedric De Schepper
 *
 */

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
     * @brief parse a player entity
     * @param j json to get the data from
     * @return player entity
     */
    model::PlayerShip::Shared parse_player(const json& j);

    /**
     * @brief parse a level
     * @param file_name name of the json file
     * @return level for the game
     */
    model::Level::Shared parse_level(const std::string& file_name);

    /**
     * @brief parse the model for the game
     * @param j json to get the data from
     * @param model model used for the game MVC
     */
    void parse_model(const json &j, model::Model::Shared& model);

    /**
     * @brief parse the view for the game
     * @param j json to get the data from
     * @param view view used for the game MVC
     */
    void parse_view(const json& j, view::View::Shared& view);
}

#endif //GRADIUS_PARSERS_H
