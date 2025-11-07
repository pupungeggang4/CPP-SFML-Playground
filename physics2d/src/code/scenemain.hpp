#pragma once
#include "general.hpp"
#include "fdef.hpp"
#include "game.hpp"

class SceneMain {
    public:
        static void loop(shared_ptr<Game>);
        static void render(shared_ptr<Game>);
};