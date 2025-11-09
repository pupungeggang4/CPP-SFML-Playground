#pragma once
#include "general.hpp"

class Game;

class SceneMain {
    public:
        static void loop(shared_ptr<Game>);
        static void render(shared_ptr<Game>);
};