
#include "Parsers.h"
#include "Model.h"
#include "Obstacle.h"
#include "EnemyShip.h"
#include "Exceptions.h"

#include <iostream>
#include <fstream>

namespace parsers{


    model::PlayerShip::Shared parse_player(const json& j){

        auto input = j.at("PlayerShip");

        auto length = j.at("PlayerShip").at("length").get<float>();

        auto width= input.at("width").get<float>();
        auto x_pos = input.at("x_position").get<float>();
        auto y_pos = input.at("y_position").get<float>();
        auto speed = input.at("speed").get<float>();

        auto health = input.at("health").get<int>();
        auto damage = input.at("damage").get<int>();

        auto time_before_shot = input.at("time_before_shot").get<double>();

        return std::move(std::make_shared<model::PlayerShip>(length, width,x_pos,y_pos,speed,health,damage,time_before_shot));
    }

    model::Level::Shared parse_level(const std::string& file_name){
        std::string correct_path = "../input/" + file_name;

        std::ifstream i(correct_path);
        json j;

        i >> j;

        model::Level::Shared level = std::make_shared<model::Level>();

        for(const auto& wave_input : j){

            model::Wave::Shared wave = std::make_shared<model::Wave>();

            wave->set_time(wave_input.at("time").get<double>());

            for(const auto& enemy_input : wave_input.at("enemies")){

                auto type = enemy_input.at("type").get<std::string>();

                auto entity_specs = enemy_input.at("specs");

                auto length = entity_specs.at("length").get<float>();
                auto width= entity_specs.at("width").get<float>();
                auto x_pos = entity_specs.at("x_position").get<float>();
                auto y_pos = entity_specs.at("y_position").get<float>();
                auto speed = entity_specs.at("speed").get<float>();

                auto health = entity_specs.at("health").get<int>();
                auto damage = entity_specs.at("damage").get<int>();

                if(type == "Obstacle"){
                    model::Obstacle::Shared obstacle = std::make_shared<model::Obstacle>
                            (length, width,x_pos,y_pos,speed,health,damage);

                    wave->add_entity(obstacle);
                }
                else if(type == "EnemyShip"){
                    auto time_before_shot = entity_specs.at("time_before_shot").get<double>();

                    model::EnemyShip::Shared ship = std::make_shared<model::EnemyShip>
                            (length, width,x_pos,y_pos,speed,health,damage,time_before_shot);

                    wave->add_entity(ship);
                }

            }

            level->add_wave(wave);


        }

        return std::move(level);
    }

    void parse_model(const json &j, model::Model::Shared& model){
        model->set_player(parse_player(j));
        model->create_all_world_entities();

        auto levels = j.at("Levels").get<std::vector<std::string>>();

        for(const std::string& level_name : levels){

            model->add_level(parse_level(level_name));
        }

    }

    void parse_view(const json& j, view::View::Shared& view){

        for(const auto& value : j.at("Textures")){

            const std::string type = value.at("name").get<std::string>();
            std::string image_name = value.at("texture").get<std::string>();

            const std::string location = "../input/" + image_name;
            sf::Texture texture;

            if(!texture.loadFromFile(location)){
                throw exceptions::TextureFileException(image_name);
            }
            view->add_texture(texture, type);
        }
    }
}