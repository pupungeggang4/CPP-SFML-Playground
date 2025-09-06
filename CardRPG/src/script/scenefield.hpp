#pragma once
#include "general.hpp"
#include "fdef.hpp"

class SceneField {
    public:
        SceneField();
        void loop(shared_ptr<Game> game);
        void render(shared_ptr<Game> game);
};