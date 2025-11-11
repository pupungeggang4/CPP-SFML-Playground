#pragma once
#include "general.hpp"

class FieldPlayer;
class Drop;
class Game;

class Field {
    public:
        sf::FloatRect camera = {{0, 0}, {1280, 720}};
        shared_ptr<FieldPlayer> player;
        std::vector<shared_ptr<Drop>> drop = {};
        shared_ptr<Drop> dropCurrent;
    
        Field(shared_ptr<Game>);
        void handleTick(shared_ptr<Game>);
        void render(shared_ptr<Game>);
};


class Entity {
    public:
        sf::FloatRect rect = {{0, 0}, {40, 40}};
        sf::Texture t = sf::Texture();
        sf::RenderTexture rt = sf::RenderTexture({80, 80});
        sf::Sprite sprite = sf::Sprite(t), spriteOut = sf::Sprite(t);

        Entity(shared_ptr<Game>);
        void handleTick(shared_ptr<Game>);
        void render(shared_ptr<Game>);
};

class Unit : public Entity {
    public:
        Unit(shared_ptr<Game>);
        //void handleTick(shared_ptr<Game>);
        //void render(shared_ptr<Game>)
};

class FieldPlayer : public Unit {
    public:
        float speed = 320.0f;
        int level = 1, exp = 0, expMax = 20, gold = 50;
        float energy = 0.0f, energyMax = 8.0f, life = 120.0f, lifeMax = 120.0f;
        FieldPlayer(shared_ptr<Game>);
        void handleTick(shared_ptr<Game>);
        void move(shared_ptr<Game>);
        void render(shared_ptr<Game>);
};

class Drop : public Entity {
    public:
        std::string type;
        int amount;
        Drop(shared_ptr<Game>, std::string, int);
        void handleTick(shared_ptr<Game>);
        void render(shared_ptr<Game>);
};

class Projectile : public Entity {
    public:
};