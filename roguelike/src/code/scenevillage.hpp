#pragma once
#include "general.hpp"
#include "scene.hpp"

class Game;

class SceneVillage : public Scene {
    public:
        SceneVillage();
        void loop(shared_ptr<Game>);
        void render(shared_ptr<Game>);
        void keyDown(shared_ptr<Game>, int);
        void keyUp(shared_ptr<Game>, int);
};