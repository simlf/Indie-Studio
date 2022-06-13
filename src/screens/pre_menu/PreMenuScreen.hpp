/**
 * @file PreMenuScreen.hpp
 * @author Victor (victor.harri-chal@epitech.eu)
 * @brief The screen for the pre-menu
 * @version 0.1
 * @date 2022-06-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef PRE_MENU_SCREEN_HPP_
#define PRE_MENU_SCREEN_HPP_

#include <vector>
#include "../../ecs/entity/Entity.hpp"
#include "../IScreen.hpp"
#include "../ecs/system/Draw2D/Draw2D.hpp"
#include "../player/Player.hpp"

namespace indie
{
    namespace menu
    {
        class PreMenuScreen : public IScreen {
          public:
            PreMenuScreen(std::vector<player::Player> *players);
            ~PreMenuScreen() = default;
            void init() override;
            void draw() override;
            void update() override;
            int handleEvent(indie::Event &event) override;
            void addEntity(std::unique_ptr<indie::ecs::entity::Entity> entity) override;
            void addSystem(std::unique_ptr<indie::ecs::system::ISystem> system) override;

            int getNbPlayers() const;
            bool isPlayer2Playing() const;
            bool isPlayer3Playing() const;
            bool isPlayer4Playing() const;
            bool getIsGameReady() const;
            void setIsGameReady(bool is_game_ready);

            bool check_if_players_are_ready();
            void handlePlayer1(indie::Event &event);
            void handlePlayer2(indie::Event &event);
            void handlePlayer3(indie::Event &event);
            void handlePlayer4(indie::Event &event);

          private:
            std::vector<std::unique_ptr<indie::ecs::entity::Entity>> _entities;
            std::vector<std::unique_ptr<indie::ecs::system::ISystem>> _systems;
            std::vector<player::Player> *_players;
            int _nb_players;

            bool _is_player2_playing;
            bool _is_player3_playing;
            bool _is_player4_playing;

            bool _is_player1_ready;
            bool _is_player2_ready;
            bool _is_player3_ready;
            bool _is_player4_ready;

            int _player2_pos;
            int _player3_pos;
            int _player4_pos;

            int _player1_ready_pos;
            int _player2_ready_pos;
            int _player3_ready_pos;
            int _player4_ready_pos;

            bool _game_is_ready;
        };
    } // namespace menu
} // namespace indie

#endif /* !PRE_MENU_SCREEN_HPP_ */