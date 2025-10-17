#pragma once
#include "general.hpp"

class UI;
class Locale;

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
        static std::vector<std::vector<int>> titleArrow;
        static std::unordered_map<std::string, std::vector<int>> village;
        static std::unordered_map<std::string, std::vector<int>> battle;
        static std::unordered_map<std::string, std::vector<int>> menu;
};

class Locale {
    public:
        static std::unordered_map<std::string, std::unordered_map<std::string, sf::String>> data;
};

class Render {
    public:
        static void fillText(sf::RenderWindow& window, sf::Text rText, sf::String text, std::vector<int> pos);
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

class Game {
    public:
        sf::RenderWindow window;
        unsigned int width, height;
        sf::RectangleShape rRect;
        sf::Font neodgm;
        std::unordered_map<std::string, sf::Texture> tex; 
        sf::Text rText = sf::Text(neodgm, "", 32);
        sf::Texture t = sf::Texture();
        sf::Sprite sprite = sf::Sprite(t);

        std::string scene = "title", state = "";
        bool menu = false;
        int selectedTitle = 0;

        std::string lang = "en";
        std::unordered_map<std::string, sf::String> locale;

        Game();
        void loadFont();
        void loadImage();
        void run(shared_ptr<Game> game);
        void handleScene(shared_ptr<Game> game);
        void handleInput(shared_ptr<Game> game);
};
