#pragma once
#include "general.hpp"

typedef std::unordered_map<std::string, std::vector<float>> UI;

extern UI UITitle;
extern UI UIBattle;
extern UI UICollection;

class Card;
class Crystal;
class Unit;

class Game;
class Battle;

class Render;
class SceneTitle;
class SceneGame;

class Card {
    public:
        std::string name;
        std::string element;
        std::string rarity;
        std::string type;
        int attack, hp;
        std::vector<shared_ptr<Crystal>> crystal;

        Card();
        void setData(int ID);
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
        std::string scene, state;
        Game();
        void run(shared_ptr<Game> game);
};

class Battle {

};

class Render {
    public:
        static void strokeRectUI(sf::RenderWindow& window, sf::RectangleShape r, std::vector<float> rect);
        static void fillTextUI(sf::RenderWindow& window, sf::Text t, std::string text, std::vector<float> pos);
};

class SceneTitle {
    public:
        static void loop(shared_ptr<Game> game);
        static void render(shared_ptr<Game> game);
        static void mouseUp(shared_ptr<Game> game, sf::Vector2f pos);
};

class SceneGame {
    public:
        static void loop(shared_ptr<Game> game);
        static void render(shared_ptr<Game> game);
};

bool pointInsideRectUI(sf::Vector2f point, std::vector<float> rect);