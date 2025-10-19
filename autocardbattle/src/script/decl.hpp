#pragma once
#include "general.hpp"

class UI;

class Card;
class Crystal;
class Unit;

class Game;
class Battle;

class Render;
class Func;

class SceneTitle;
class SceneReady;
class SceneBattle;
class SceneCollection;

class UI {
    public:
        static std::unordered_map<std::string, std::vector<int>> title;
        static std::unordered_map<std::string, std::vector<int>> ready;
        static std::unordered_map<std::string, std::vector<int>> battle;
};

class Card {
    public:
        std::string name;
        std::string element;
        std::string rarity;
        std::string type;
        int attack, hp;
        std::vector<shared_ptr<Crystal>> crystal;

        Card();
        void setData(int);
};

class Crystal {
    public:
        std::string name;
        std::string element;
};

class Unit {
    public:
        int hp, hpMax, attack;
};

class Game {
    public:
        sf::RenderWindow window;
        sf::Font neodgm = sf::Font("font/neodgm.ttf");
        sf::RectangleShape rTmpRect = sf::RectangleShape({0.0f, 0.0f});
        sf::Text rTmpText = sf::Text(neodgm, "Hello", 32);

        unsigned int width, height;
        std::string scene = "title", state = ""; bool menu = false;
        Game();
        void run(shared_ptr<Game>);

        void handleScene(shared_ptr<Game>);
        void handleInput(shared_ptr<Game>);
};

class Battle {

};

class Render {
    public:
        static void drawRect(sf::RenderTarget&, sf::RectangleShape, std::vector<int>, float);
        static void fillText(sf::RenderTarget&, sf::Text, sf::String, std::vector<int>);
        static void drawTexture(sf::RenderTarget&, sf::Sprite, sf::Texture, std::vector<int>);
};

class SceneTitle {
    public:
        static void loop(shared_ptr<Game>);
        static void render(shared_ptr<Game>);
        static void mouseUp(shared_ptr<Game>, sf::Vector2f);
};

class SceneReady {
    public:
        static void loop(shared_ptr<Game>);
        static void render(shared_ptr<Game>);
        static void mouseUp(shared_ptr<Game>, sf::Vector2f);
};

class SceneBattle {
    public:
        static void loop(shared_ptr<Game>);
        static void render(shared_ptr<Game>);
        static void mouseUp(shared_ptr<Game>, sf::Vector2f);
};

class SceneCollection {
    public:
        static void loop(shared_ptr<Game>);
        static void render(shared_ptr<Game>);
        static void mouseUp(shared_ptr<Game>, sf::Vector2f);
};

class Func{
    public:
        static bool pointInsideRectUI(sf::Vector2f, std::vector<int>);
};
