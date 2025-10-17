#pragma once
#include "general.hpp"

class UI;
class Data;
class Locale;

class Field;
class Entity;
class Unit;
class FieldPlayer;

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

class Field : public enable_shared_from_this<Field> {
    public:
        shared_ptr<FieldPlayer> player;
        sf::FloatRect cam = {{0.0, 0.0}, {1280.0, 720.0}};

        Field();
        void handleTick(shared_ptr<Field>, shared_ptr<Game>);
        void render(sf::RenderTarget&, shared_ptr<Field>, shared_ptr<Game>);
};

class Entity {

};

class Unit {

};

class FieldPlayer {
    public:
        sf::FloatRect rect = {{0.0, 0.0}, {80.0, 80.0}};
        sf::RenderTexture rTex = sf::RenderTexture({80, 80});
        sf::Texture tex = sf::Texture();
        sf::Sprite sprite = sf::Sprite(tex);
        sf::Sprite spriteOut = sf::Sprite(tex);

        FieldPlayer();
        void handleTick(shared_ptr<Field>, shared_ptr<Game>);
        void render(sf::RenderTarget&, shared_ptr<Field> field, shared_ptr<Game>);
};

class Render {
    public:
        static void init(shared_ptr<Game>);
        static void drawRect(sf::RenderTarget&, sf::RectangleShape, std::vector<int>, float);
        static void fillText(sf::RenderTarget&, sf::Text, sf::String, std::vector<int>);
        static void drawImage(sf::RenderTarget&, sf::Sprite, sf::Texture, std::vector<int>);
        static void renderMenu(sf::RenderTarget&, shared_ptr<Game>);
        static void drawCenterCam(sf::RenderTarget& rt, sf::Sprite sprite, sf::FloatRect rect, sf::FloatRect cam);
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
        sf::Clock clock;
        float framePrevious, frameCurrent, delta;

        std::string scene = "title";
        std::string state = "";
        bool menu = false;
        std::string lang = "en";
        std::unordered_map<std::string, sf::String> locale;

        int selectedTitle = 0;
        int selectedMenu = 0;

        std::unordered_map<std::string, bool> keyPressed = {
            {"left", false}, {"right", false}, {"up", false}, {"down", false}
        };

        shared_ptr<Field> field;

        Game();
        void run(shared_ptr<Game>);
        void handleInput(shared_ptr<Game>);
        void handleScene(shared_ptr<Game>);
};