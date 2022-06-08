/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** Game
*/

#include "Game.hpp"
#include <algorithm>
#include <chrono>
#include <iostream>
#include <memory>
#include "../ecs/system/Collide/Collide.hpp"
#include "../ecs/system/Draw2D/Draw2D.hpp"
#include "../ecs/system/Draw3D/Draw3D.hpp"
#include "../ecs/system/Explodable/Explodable.hpp"
#include "../ecs/system/Movement/Movement.hpp"
#include "../ecs/system/Sound/Sound.hpp"
#include "../gameEvents/GameEvents.hpp"
#include "../raylib/Raylib.hpp"
#include "../screens/IScreen.hpp"

indie::Game::Game(size_t baseFps)
{
    _fps = baseFps;
    _actualScreen = Screens::Menu;
    _menu = new indie::menu::MenuScreen;
    _game = new indie::menu::GameScreen;
}

indie::Game::~Game()
{
    delete _menu;
    delete _game;
}

bool indie::Game::processEvents()
{
    GameEvents gameEvent;

    bool ret = gameEvent.inputUpdate(_event);
    this->_game->handleEvent(_event);
    return (ret);
}

void indie::Game::update(float delta)
{
    (void)delta;
    return;
}

void indie::Game::draw()
{
    switch (_actualScreen) {
        case Screens::Menu: _menu->draw(); break;
        case Screens::Game: _game->draw(); break;
        default: break;
    }
}

void indie::Game::run()
{
    int64_t newTime = 0;
    int64_t currentTime =
        std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch())
            .count();
    int64_t accumulator = 0;
    int64_t draw_aq = 0;
    const float initUpdateMs = static_cast<float>(_fps) * 1000;
    float updateMs = initUpdateMs;
    std::unique_ptr<indie::ecs::entity::Entity> entity =
        std::make_unique<indie::ecs::entity::Entity>(indie::ecs::entity::entityType::TEXT);
    std::unique_ptr<indie::ecs::entity::Entity> entity2 =
        std::make_unique<indie::ecs::entity::Entity>(indie::ecs::entity::entityType::TEXT);
    std::unique_ptr<indie::ecs::entity::Entity> entity4 =
        std::make_unique<indie::ecs::entity::Entity>(indie::ecs::entity::entityType::PLAYER1);
    std::unique_ptr<indie::ecs::entity::Entity> entity5 =
        std::make_unique<indie::ecs::entity::Entity>(indie::ecs::entity::entityType::PLAYER2);
    std::unique_ptr<indie::ecs::system::ISystem> draw2DSystem = std::make_unique<indie::ecs::system::Draw2DSystem>();
    std::unique_ptr<indie::ecs::system::ISystem> draw3DSystem = std::make_unique<indie::ecs::system::Draw3DSystem>();
    std::unique_ptr<indie::ecs::system::ISystem> movementSystem =
        std::make_unique<indie::ecs::system::MovementSystem>();
    std::unique_ptr<indie::ecs::system::ISystem> soundSystem = std::make_unique<indie::ecs::system::Sound>();
    std::unique_ptr<indie::ecs::system::ISystem> collideSystem = std::make_unique<indie::ecs::system::Collide>();
    std::unique_ptr<indie::ecs::system::Explodable> explodeSystem = std::make_unique<indie::ecs::system::Explodable>();

    entity->addComponent<indie::ecs::component::Transform>(
        static_cast<float>(100.0), static_cast<float>(100.0), static_cast<float>(0.0), static_cast<float>(0.0));
    entity->addComponent<indie::ecs::component::Drawable2D>(
        "INDIE STUDIOOOO MENU BONJOURRRRRR", static_cast<float>(50.0), BLACK);
    this->_menu->addEntity(std::move(entity));

    entity2->addComponent<indie::ecs::component::Transform>(
        static_cast<float>(100.0), static_cast<float>(100.0), static_cast<float>(0.0), static_cast<float>(0.0));
    entity2->addComponent<indie::ecs::component::Drawable2D>(
        "src/button.png", static_cast<float>(150.0), static_cast<float>(350.0), WHITE);
    entity4->addComponent<indie::ecs::component::Transform>(
        static_cast<float>(1.0), static_cast<float>(1.0), static_cast<float>(-0.02), static_cast<float>(0.0));
    entity4->addComponent<indie::ecs::component::Drawable3D>(
        "src/boite.png", static_cast<float>(1.0), static_cast<float>(1.0), static_cast<float>(1.0), WHITE);
    entity4->addComponent<indie::ecs::component::Collide>();
    entity5->addComponent<indie::ecs::component::Transform>(
        static_cast<float>(-2.0), static_cast<float>(-1.0), static_cast<float>(0.02), static_cast<float>(0.0));
    entity5->addComponent<indie::ecs::component::Drawable3D>(
        "src/boite.png", static_cast<float>(1.0), static_cast<float>(1.0), static_cast<float>(1.0), BLUE);
    entity5->addComponent<indie::ecs::component::Collide>();
    //  entity4->addComponent<indie::ecs::component::Sound>("src/maybe-next-time.wav", false);

    this->_game->addEntity(std::move(entity2));
    this->_game->addEntity(std::move(entity4));
    this->_game->addEntity(std::move(entity5));
    this->_game->addSystem(std::move(draw2DSystem));
    this->_game->addSystem(std::move(draw3DSystem));
    this->_game->addSystem(std::move(movementSystem));
    this->_game->addSystem(std::move(soundSystem));
    this->_game->addSystem(std::move(collideSystem));
    this->_game->addSystem(std::move(explodeSystem));

    while (!indie::raylib::Window::windowShouldClose()) {
        newTime =
            std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch())
                .count();
        accumulator += newTime - currentTime;
        if (accumulator > 10 * initUpdateMs)
            updateMs = accumulator;
        currentTime = newTime;
        if (!processEvents())
            break;
        while (accumulator >= updateMs) {
            update(updateMs / 1000.f);
            accumulator -= updateMs;
        }
        updateMs = initUpdateMs;
        draw_aq += accumulator;
        draw();
        _actualScreen = Screens::Game;
        draw_aq = 0;
    }
    indie::raylib::Window::destroyWindow();
}

void indie::Game::setActualScreen(Screens newScreen)
{
    _actualScreen = newScreen;
}
