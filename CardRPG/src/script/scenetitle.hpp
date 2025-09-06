#pragma once
#include "general.hpp"
#include "fdef.hpp"

class SceneTitle {
    public:
        SceneTitle();
        static void loop(shared_ptr<Game> game);
        static void render(shared_ptr<Game> game);
};