/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** Rectangle
*/

#include "Rectangle.hpp"

indie::raylib::Rectangle::Rectangle(float x, float y, float width, float height)
{
    _rectangle.x = x;
    _rectangle.y = y;
    _rectangle.width = width;
    _rectangle.height = height;
}

indie::raylib::Rectangle::Rectangle(float x, float y, float width, float height, ::Color color)
{
    _rectangle.x = x;
    _rectangle.y = y;
    _rectangle.width = width;
    _rectangle.height = height;
    _color = color;
}

::Vector2 indie::raylib::Rectangle::getSize() const {
    return {_rectangle.width, _rectangle.height};
}

void indie::raylib::Rectangle::setSize(float newWidth, float newHeight) {
    _rectangle.width = newWidth;
    _rectangle.height = newHeight;
}

::Vector2 indie::raylib::Rectangle::getPosition() const {
    return {_rectangle.width, _rectangle.height};
}

void indie::raylib::Rectangle::setPosition(float posX, float posY) {
    _rectangle.x = posX;
    _rectangle.y = posY;
}

::Color indie::raylib::Rectangle::getColor() const {
    return _color;
}

void indie::raylib::Rectangle::setColor(::Color color) {
    _color = color;
}

void indie::raylib::Rectangle::draw()
{
    ::DrawRectangle(_rectangle.x, _rectangle.y,  _rectangle.width,  _rectangle.height, _color);
}

void indie::raylib::Rectangle::draw(Color color)
{
    ::DrawRectangle(_rectangle.x, _rectangle.y,  _rectangle.width,  _rectangle.height, color);
}

::Rectangle indie::raylib::Rectangle::getCollision(::Rectangle rec2) const {
    return ::GetCollisionRec(_rectangle, rec2);
}

bool indie::raylib::Rectangle::checkCollision(::Rectangle rec2) const {
    return ::CheckCollisionRecs(_rectangle, rec2);
}
