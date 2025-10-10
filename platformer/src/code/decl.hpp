#pragma once
#include "general.hpp"

class UI;
class Data;
class Asset;

class Field;
class Entity;
class Unit;

class Func;
class Render;

class SceneTitle;
class SceneField;
class Game;

class UI {
    public:
        static std::unordered_map<std::string, std::vector<int>> title;
        static std::unordered_map<std::string, std::vector<int>> field;
};

class Data {
    
};

class Asset {

};

class Field {

};

class Entity {

};

class Unit {

};

class SceneTitle {

};

class SceneField {

};

class Game {
    public:
        unsigned int width, height;
        sf::RenderWindow window;
        std::string scene = "title";
        std::string state = "";

        Game();
        void run(shared_ptr<Game>);
        void handleInput(shared_ptr<Game>);
        void handleScene(shared_ptr<Game>);
};
