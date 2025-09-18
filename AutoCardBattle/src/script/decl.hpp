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

};

class Crystal {

};

class Unit {

};

class Game {
    public:
        sf::RenderWindow window;
        sf::Font neodgm = sf::Font("font/neodgm.ttf");
        sf::RectangleShape rTmpRect = sf::RectangleShape({0.0f, 0.0f});
        sf::Text rTmpText = sf::Text(neodgm, "Hello", 32);
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

};

class SceneGame {

};

bool pointInsideRectUI(sf::Vector2f point, sf::FloatRect rect);