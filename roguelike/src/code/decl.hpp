#pragma once
#include "general.hpp"

class Res;
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
        static std::unordered_map<std::string, std::vector<std::vector<int>>> title;
        static std::unordered_map<std::string, std::vector<int>> village;
        static std::unordered_map<std::string, std::vector<int>> battle;
        static std::unordered_map<std::string, std::vector<int>> menu;
};

class Render {
    public:
        static void fillText(sf::RenderWindow& window, sf::Text rText, std::string text, std::vector<int> pos);
        static void strokeRect(sf::RenderWindow& window, sf::RectangleShape rRect, std::vector<int> rect);
        static void drawTexture(sf::RenderWindow& window, sf::Texture texture, sf::Sprite sprite, std::vector<int> pos);
};

class Func {
    public:
        static bool pointInsideRectUI(sf::Vector2i pos, sf::IntRect rect);
};

class SceneTitle {
    public:
        static void loop(shared_ptr<Game> game);
        static void render(shared_ptr<Game> game);
        static void keyDown(shared_ptr<Game> game, int key);
        static void keyUp(shared_ptr<Game> game, int key);
};

class SceneVillage {

};

class SceneBattle {
    
};

class Res {
    public:
        static sf::Font neodgm;
        static sf::Texture arrow;
};

class Game {
    public:
        sf::RenderWindow window;
        unsigned int width, height;
        sf::Text rText = sf::Text(Res::neodgm);
        sf::RectangleShape rRect;
        sf::Texture t = sf::Texture();
        sf::Sprite sprite = sf::Sprite(t);
        std::string scene, state;
        bool menu;
        int selectedTitle;

        Game();
        void run(shared_ptr<Game> game);
        void handleScene(shared_ptr<Game> game);
        void handleInput(shared_ptr<Game> game);
};
