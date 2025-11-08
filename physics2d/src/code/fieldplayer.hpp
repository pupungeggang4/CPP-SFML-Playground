#pragma once
#include "wrapper.hpp"


class FieldPlayer : public Entity {
    public:
        sf::FloatRect rect = sf::FloatRect({{0, 0}, {80, 80}});
        sf::RectangleShape rectS = sf::RectangleShape({80, 80});
        sf::Vector2f velocity = sf::Vector2f({0, 0});
        float speed = 320.0f;

        FieldPlayer();
        void handleTick(shared_ptr<Game>);
        void render(shared_ptr<Game>);
};