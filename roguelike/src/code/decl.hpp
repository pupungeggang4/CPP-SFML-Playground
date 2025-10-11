#pragma once
#include "general.hpp"

class UI;

class Adventure;
class Player;
class Unit;
class Card;

class Render;
class Func;

class SceneTitle;
class SceneVillage;
class SceneBattle;

class Game;

class UI {
    public:
        static std::unordered_map<std::string, std::vector<int>> title;
        static std::unordered_map<std::string, std::vector<int>> village;
        static std::unordered_map<std::string, std::vector<int>> battle;
        static std::unordered_map<std::string, std::vector<int>> menu;
};

class Render {
    public:
        static void renderText(sf::RenderWindow& window, sf::Text rText, std::string text, std::vector<float> pos);
        static void strokeRect(sf::RenderWindow& window, sf::RectangleShape rRect, std::vector<float> rect);
};

class Func {
    public:
        static bool pointInsideRectUI(sf::Vector2i pos, sf::IntRect rect);
};

class SceneTitle {

};

class SceneVillage {

};

class SceneBattle {
    
};

class Game {
    public:
        sf::RenderWindow window;
        unsigned int width, height;
        sf::Text rText; sf::RectangleShape rRect; sf::Font neodgm;
        Game();
        void run(shared_ptr<Game> game);
        void handleScene(shared_ptr<Game> game);
        void handleInput(shared_ptr<Game> game);
};