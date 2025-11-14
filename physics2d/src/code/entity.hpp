#pragma once
#include "general.hpp"

class Game;

class Entity : public std::enable_shared_from_this<Entity> {
    public:
        sf::Sprite sprite;
        sf::FloatRect rect = sf::FloatRect({{0, 0}, {40, 40}});
        sf::Vector2f velocity = sf::Vector2f({0, 0});
        bool solid = false, floor = false, fall = false;

        Entity();
        virtual void handleTick(shared_ptr<Game>);
        virtual void render(shared_ptr<Game>);
        void handleCollideX(shared_ptr<Game>);
        void handleFall(shared_ptr<Game>);
        void handleCollideUp(shared_ptr<Game>);
};

class Coin : public Entity {
    public:
        std::vector<sf::IntRect> frameCoord = {
            {{0, 0}, {40, 40}}, {{40, 0}, {40, 40}}, {{80, 0}, {40, 40}}, {{120, 0}, {40, 40}}
        };
        int frames = 4, frameCurrent = 0; float frameTime = 0, frameInterval = 0.2;

        Coin();
        void handleTick(shared_ptr<Game>);
        void render(shared_ptr<Game>);
};

class Wall : public Entity {
    public:
        Wall();
        void render(shared_ptr<Game>);
};

class Platform : public Entity {
    public:
        Platform();
        void render(shared_ptr<Game>);
};

class FieldPlayer : public Entity {
    public:
        float speed = 320.0f, gravity = 800.0f, terminalSpeed = 800.0f, jumpPower = -400.0f;
        int coin = 0;

        FieldPlayer();
        void jump();
        void handleTick(shared_ptr<Game>);
        void render(shared_ptr<Game>);
};
