/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Entity
*/

#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "../component/Drawable/Drawable2D.hpp"
#include "../component/Drawable/Drawable3D.hpp"
#include "../component/IComponent.hpp"
#include "../component/Transform/Transform.hpp"

namespace indie
{
    namespace ecs
    {
        class Entity {
          public:
            Entity();
            ~Entity();

            template <typename T, typename... Args> void addComponent(Args... args)
            {
                this->_componentVector.push_back(std::unique_ptr<T>(new T{std::forward<Args>(args)...}));
            }

            bool hasCompoType(indie::ecs::compoType type)
            {
                for (auto &compo : _componentVector) {
                    if (compo->getType() == type)
                        return (true);
                }
                return (false);
            }

            template <typename T> T *getComponent(indie::ecs::compoType type)
            {
                for (auto &compo : _componentVector) {
                    if (compo->getType() == type) {
                        return (dynamic_cast<T *>(compo.get()));
                    }
                }
                return (nullptr);
            }

            /*void draw(ecs::drawableType drawType)
            {
                for (auto &compo : _componentVector) {
                    if (compo->isDrawable(drawType) == true && this->_alive == true) {
                        ecs::Drawable *drawableCompo = dynamic_cast<ecs::Drawable *>(compo.get());
                        ecs::Transform *component = getComponent<ecs::Transform>(ecs::compoType::TRANSFORM);
                        drawableCompo->draw(*component);
                    }
                }
            }*/

            void setAlive(bool alive)
            {
                this->_alive = alive;
            }

            bool getAlive(void)
            {
                return (this->_alive);
            }

          protected:
          private:
            std::vector<std::unique_ptr<IComponent>> _componentVector;
            bool _alive;
        };
    } // namespace ecs
} // namespace indie

#endif /* !ENTITY_HPP_ */
