#pragma once
#include "res.hpp"
#include "general.hpp"

class Game;

class Entity {
    public:
        Entity();
        virtual void handleTick(shared_ptr<Game>);
        virtual void render(shared_ptr<Game>);
};

class Coin : public Entity {
    public:
        sf::Sprite sprite;
        sf::FloatRect rect = sf::FloatRect({{0, 0}, {40, 40}});
        std::vector<sf::IntRect> frameCoord = {
            {{0, 0}, {40, 40}}, {{40, 0}, {40, 40}}, {{80, 0}, {40, 40}}, {{120, 0}, {40, 40}}
        };
        int frames = 4, frameCurrent = 0; float frameTime = 0, frameInterval = 0.2;

        Coin();
        void render(shared_ptr<Game>);
};

class Wall : public Entity {
    public:
        sf::Sprite sprite;
        sf::FloatRect rect = sf::FloatRect({{0, 80}, {160, 40}});
        sf::RectangleShape rectS = sf::RectangleShape({160, 40});
        Wall();
        void render(shared_ptr<Game>);
};

class Platform : public Entity {
    public:
        sf::FloatRect rect = sf::FloatRect({{200, 80}, {160, 40}});
        sf::RectangleShape rectS = sf::RectangleShape({160, 40});
        Platform();
        void render(shared_ptr<Game>);
};