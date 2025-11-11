#pragma once
#include "general.hpp"

class Game;
class VillagePlayer;
class VillagePortal;

class Village {
    public:
        sf::FloatRect camera = {{0, 0}, {1280, 720}};
        shared_ptr<VillagePlayer> player;
        shared_ptr<VillagePortal> portalBattle;

        Village(shared_ptr<Game>);
        void handleTick(shared_ptr<Game>);
        void render(shared_ptr<Game>);
};

class VillagePlayer {
    public:
        sf::FloatRect rect = {{0, 0}, {80, 80}};
        sf::RenderTexture rt;
        sf::Texture t;
        sf::Sprite sprite = sf::Sprite(t), spriteOut = sf::Sprite(t);

        float speed = 320.0f;

        VillagePlayer(shared_ptr<Game>);
        void handleTick(shared_ptr<Game>);
        void render(shared_ptr<Game>);
        void move(shared_ptr<Game>);
        void interact(shared_ptr<Game>);
};

class VillagePortal {
    public:
        sf::FloatRect rect = {{0, -200}, {80, 80}};
        sf::RenderTexture rt;
        sf::Texture t;
        sf::Sprite sprite = sf::Sprite(t), spriteOut = sf::Sprite(t);

        VillagePortal(shared_ptr<Game>);
        void render(shared_ptr<Game>);
};