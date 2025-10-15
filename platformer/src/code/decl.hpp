#pragma once
#include "general.hpp"

class UI;
class Data;
class Locale;

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
        static std::vector<std::vector<int>> titleArrow;
        static std::unordered_map<std::string, std::vector<int>> field;
        static std::unordered_map<std::string, std::vector<int>> menu;
        static std::vector<std::vector<int>> menuArrow;
};

class Locale {
    public:
        static LocaleForm data;
};

class Data {
    
};

class Field {

};

class Entity {

};

class Unit {

};

class Render {
    public:
        static void init(shared_ptr<Game>);
        static void drawRect(sf::RenderWindow&, sf::RectangleShape, std::vector<int>, float);
        static void fillText(sf::RenderWindow&, sf::Text, sf::String, std::vector<int>);
        static void drawImage(sf::RenderWindow&, sf::Sprite, sf::Texture, std::vector<int>);
        static void renderMenu(sf::RenderWindow&, shared_ptr<Game>);
};

class SceneTitle {
    public:
        static void loop(shared_ptr<Game>);
        static void render(shared_ptr<Game>);
        static void keyDown(shared_ptr<Game>, int);
        static void keyUp(shared_ptr<Game>, int);
};

class SceneField {
    public:
        static void loop(shared_ptr<Game>);
        static void render(shared_ptr<Game>);
        static void keyDown(shared_ptr<Game>, int);
        static void keyUp(shared_ptr<Game>, int);
};

class Game {
    public:
        unsigned int width, height;
        sf::RenderWindow window;
        std::unordered_map<std::string, sf::Texture> tex;
        sf::RectangleShape rRect;
        sf::Font neodgm = sf::Font("font/neodgm.ttf");
        sf::Text rText = sf::Text(neodgm, "", 32);
        sf::Texture t = sf::Texture(); sf::Sprite sprite = sf::Sprite(t);

        std::string scene = "title";
        std::string state = "";
        bool menu = false;
        std::string lang = "en";
        std::unordered_map<std::string, sf::String> locale;

        int selectedTitle = 0;
        int selectedMenu = 0;

        Game();
        void run(shared_ptr<Game>);
        void handleInput(shared_ptr<Game>);
        void handleScene(shared_ptr<Game>);
};
