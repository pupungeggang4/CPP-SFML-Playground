#pragma once
#include "wrapper.hpp"

class Entity {
    public:
        Entity();
};

class Coin : public Entity {
    public:
        sf::Texture &texture = Res::texture->at("sprite_coin");
        sf::Sprite sprite = sf::Sprite(texture);
        sf::FloatRect rect = sf::FloatRect({{0, 0}, {40, 40}});
        std::vector<sf::FloatRect> frameCoord = {
            {{0, 0}, {40, 40}}, {{40, 0}, {40, 40}}, {{80, 0}, {40, 40}}, {{120, 0}, {40, 40}}
        };
        int frames = 4, frameCurrent = 0; float frameTime = 0, frameInterval = 0.2;

        Coin();
        void render(shared_ptr<Game>);
};

