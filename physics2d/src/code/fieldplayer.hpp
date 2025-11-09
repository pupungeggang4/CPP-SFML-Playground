#pragma once
#include "general.hpp"
#include "entity.hpp"
#include "res.hpp"

class Game;

class FieldPlayer : public Entity {
    public:
        sf::Sprite sprite;
        sf::FloatRect rect = sf::FloatRect({{0, 0}, {80, 80}});
        sf::RectangleShape rectS = sf::RectangleShape({80, 80});
        sf::Vector2f velocity = sf::Vector2f({0, 0});
        float speed = 320.0f;
        int coin = 0;

        FieldPlayer();
        void handleTick(shared_ptr<Game>);
        void render(shared_ptr<Game>);
};