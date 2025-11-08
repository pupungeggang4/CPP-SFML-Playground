#pragma once
#include "wrapper.hpp"

class SceneMain {
    public:
        static void loop(shared_ptr<Game>);
        static void render(shared_ptr<Game>);
};