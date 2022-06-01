/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** Events.cpp
*/

#include "GameEvents.hpp"
#include <iostream>
#include "../raylib/Raylib.hpp"

namespace indie
{
    void GameEvents::getCharKeys(indie::Event &event)
    {
        if (indie::raylib::Event::isKeyPressed(KEY_A))
            event.key.code = 'a';
        else if (indie::raylib::Event::isKeyPressed(KEY_B))
            event.key.code = 'b';
        else if (indie::raylib::Event::isKeyPressed(KEY_C))
            event.key.code = 'c';
        else if (indie::raylib::Event::isKeyPressed(KEY_D))
            event.key.code = 'd';
        else if (indie::raylib::Event::isKeyPressed(KEY_E))
            event.key.code = 'e';
        else if (indie::raylib::Event::isKeyPressed(KEY_F))
            event.key.code = 'f';
        else if (indie::raylib::Event::isKeyPressed(KEY_G))
            event.key.code = 'g';
        else if (indie::raylib::Event::isKeyPressed(KEY_H))
            event.key.code = 'h';
        else if (indie::raylib::Event::isKeyPressed(KEY_I))
            event.key.code = 'i';
        else if (indie::raylib::Event::isKeyPressed(KEY_J))
            event.key.code = 'j';
        else if (indie::raylib::Event::isKeyPressed(KEY_K))
            event.key.code = 'k';
        else if (indie::raylib::Event::isKeyPressed(KEY_L))
            event.key.code = 'l';
        else if (indie::raylib::Event::isKeyPressed(KEY_M))
            event.key.code = 'm';
        else if (indie::raylib::Event::isKeyPressed(KEY_N))
            event.key.code = 'n';
        else if (indie::raylib::Event::isKeyPressed(KEY_O))
            event.key.code = 'o';
        else if (indie::raylib::Event::isKeyPressed(KEY_P))
            event.key.code = 'p';
        else if (indie::raylib::Event::isKeyPressed(KEY_Q))
            event.key.code = 'q';
        else if (indie::raylib::Event::isKeyPressed(KEY_R))
            event.key.code = 'r';
        else if (indie::raylib::Event::isKeyPressed(KEY_S))
            event.key.code = 's';
        else if (indie::raylib::Event::isKeyPressed(KEY_T))
            event.key.code = 't';
        else if (indie::raylib::Event::isKeyPressed(KEY_U))
            event.key.code = 'u';
        else if (indie::raylib::Event::isKeyPressed(KEY_V))
            event.key.code = 'v';
        else if (indie::raylib::Event::isKeyPressed(KEY_W))
            event.key.code = 'w';
        else if (indie::raylib::Event::isKeyPressed(KEY_X))
            event.key.code = 'x';
        else if (indie::raylib::Event::isKeyPressed(KEY_Y))
            event.key.code = 'y';
        else if (indie::raylib::Event::isKeyPressed(KEY_Z))
            event.key.code = 'z';
        else if (indie::raylib::Event::isKeyPressed(KEY_SPACE))
            event.key.code = ' ';
        else if (indie::raylib::Event::isKeyPressed(KEY_APOSTROPHE))
            event.key.code = '\'';
        else if (indie::raylib::Event::isKeyPressed(KEY_TAB))
            event.key.code = '\t';
        else
            event.key.code = '\0';
    }

    void GameEvents::getSystemKeys(indie::Event &event)
    {
        if (indie::raylib::Event::isKeyPressed(KEY_DOWN))
            event.key.down = true;
        else
            event.key.down = false;
        if (indie::raylib::Event::isKeyPressed(KEY_RIGHT))
            event.key.right = true;
        else
            event.key.right = false;
        if (indie::raylib::Event::isKeyPressed(KEY_LEFT))
            event.key.left = true;
        else
            event.key.left = false;
        if (indie::raylib::Event::isKeyPressed(KEY_UP))
            event.key.up = true;
        else
            event.key.up = false;
        if (indie::raylib::Event::isKeyPressed(KEY_ENTER))
            event.key.enter = true;
        else
            event.key.enter = false;
        if (indie::raylib::Event::isKeyPressed(KEY_LEFT_CONTROL))
            event.key.l_control = true;
        else
            event.key.l_control = false;
        if (indie::raylib::Event::isKeyPressed(KEY_RIGHT_CONTROL))
            event.key.r_control = true;
        else
            event.key.r_control = false;
        if (indie::raylib::Event::isKeyPressed(KEY_LEFT_ALT))
            event.key.l_alt = true;
        else
            event.key.l_alt = false;
        if (indie::raylib::Event::isKeyPressed(KEY_RIGHT_ALT))
            event.key.r_alt = true;
        else
            event.key.r_alt = false;
        if (indie::raylib::Event::isKeyPressed(KEY_LEFT_SHIFT))
            event.key.l_shift = true;
        else
            event.key.l_shift = false;
        if (indie::raylib::Event::isKeyPressed(KEY_RIGHT_SHIFT))
            event.key.r_shift = true;
        else
            event.key.r_shift = false;
    }

    bool GameEvents::inputUpdate(indie::Event &event)
    {
        this->getCharKeys(event);
        this->getSystemKeys(event);
        if (indie::raylib::Event::isKeyPressed(KEY_ESCAPE))
            return false;
        return true;
    }
} // namespace indie
