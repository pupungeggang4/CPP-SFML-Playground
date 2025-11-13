#pragma once
#include "general.hpp"
#include "scene.hpp"

class Game;

class SceneTitle : public Scene {
    public:
        SceneTitle(shared_ptr<Game>);
        void loop(shared_ptr<Game>);
        void render(shared_ptr<Game>);
        void keyDown(shared_ptr<Game>, int);
        void keyUp(shared_ptr<Game>, int);
};
