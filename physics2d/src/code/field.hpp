#pragma once
#include "general.hpp"

class FieldPlayer;
class Entity;
class Game;

class Field {
    public:
        sf::View view = sf::View({0, 0}, {1280, 720});
        shared_ptr<FieldPlayer> player;
        std::vector<shared_ptr<Entity>> entityList;

        Field();
        void handleTick(shared_ptr<Game>);
        void render(shared_ptr<Game>);
};
