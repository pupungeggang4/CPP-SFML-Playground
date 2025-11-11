#pragma once
#include "general.hpp"

class Game;

class Scene {
    public:
        Scene();
        virtual void loop(shared_ptr<Game>);
        virtual void render(shared_ptr<Game>);
        virtual void keyDown(shared_ptr<Game>, int);
        virtual void keyUp(shared_ptr<Game>, int);
};
