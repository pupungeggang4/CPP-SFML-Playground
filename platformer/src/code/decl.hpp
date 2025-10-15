#pragma once
#include "general.hpp"

class UI;
class Data;
class Res;

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
};

class Data {
    
};

class Res {
    public:
        static sf::Font neodgm;
        static void loadFont();
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
        static void strokeRect(sf::RenderWindow&, sf::RectangleShape, std::vector<int>);
        static void fillText(sf::RenderWindow&, sf::Text, std::string, std::vector<int>);
        static void drawImage(sf::RenderWindow&, sf::Sprite, sf::Texture, std::vector<int>);
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
        sf::Font f = sf::Font();
        sf::Text rText = sf::Text(f, "", 32);
        sf::Texture t = sf::Texture(); sf::Sprite sprite = sf::Sprite(t);

        std::string scene = "title";
        std::string state = "";

        int selectedTitle = 0;

        Game();
        void run(shared_ptr<Game>);
        void handleInput(shared_ptr<Game>);
        void handleScene(shared_ptr<Game>);
};
