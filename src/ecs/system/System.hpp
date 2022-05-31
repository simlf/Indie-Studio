/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** System
*/

#ifndef SYSTEM_HPP_
#define SYSTEM_HPP_

#include "../component/IComponent.hpp"
#include "../entity/Entity.hpp"

namespace indie
{
    namespace ecs
    {

        class ISystem {
          public:
            virtual ~ISystem() = default;

            virtual void update(std::vector<std::unique_ptr<indie::ecs::Entity>> &entities) = 0;

          private:
        };

        class MovementSystem : public ISystem {
          public:
            MovementSystem()
            {
            }
            ~MovementSystem()
            {
            }

            void update(std::vector<std::unique_ptr<indie::ecs::Entity>> &entities) override;

          private:
        };

        class Draw2DSystem : public ISystem {
          public:
            Draw2DSystem();
            ~Draw2DSystem();

            void update(std::vector<std::unique_ptr<indie::ecs::Entity>> &entities) override;

          private:
        };

        class Draw3DSystem : public ISystem {
          public:
            Draw3DSystem();
            ~Draw3DSystem();

            void update(std::vector<std::unique_ptr<indie::ecs::Entity>> &entities) override;

          private:
        };
    } // namespace ecs
    /**
     * @brief poll an event on the window
     *
     * @param event event to poll
     * @return true if there is an event in the queue
     * @return false if there isn't no event
     */
    static bool pollEvent(indie::Event &event);
} // namespace indie

#endif /* !SYSTEM_HPP_ */
