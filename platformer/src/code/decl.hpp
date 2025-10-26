#pragma once
#include "general.hpp"

class Res;
class UI;
class Data;
class Locale;

class Field;
class Entity;
class Coin;
class Unit;
class FieldPlayer;

class Func;
class Render;

class SceneTitle;
class SceneField;
class Game;

class Res {
    public:
        static std::unordered_map<std::string, sf::Texture> tex;
};

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
    public:
        shared_ptr<FieldPlayer> player;
        sf::FloatRect cam = {{0.0, 0.0}, {1280.0, 720.0}};
        std::vector<shared_ptr<Entity>> entityList = {};
        shared_ptr<Entity> entityCurrent;

        Field();
        void handleTick(shared_ptr<Game>);
        void render(shared_ptr<Game>);
};

class Entity {
    public:
        sf::RenderTexture rTex = sf::RenderTexture({40, 40});
        sf::FloatRect rect;
        sf::Texture tex;
        sf::Sprite sprite = sf::Sprite(tex), spriteOut = sf::Sprite(tex);

        std::vector<sf::IntRect> frameCoord = {};
        int frames = 0, frameCurrent = 0;
        float frameInterval = 0, frameTime = 0;

        Entity();
        virtual void render(shared_ptr<Game>);
        virtual void handleTick(shared_ptr<Game>);
};

class Coin : public Entity {
    public:
        Coin();
        void render(shared_ptr<Game>);
        void handleTick(shared_ptr<Game>);
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
        void handleTick(shared_ptr<Game>);
        void render(shared_ptr<Game>);
};

class Render {
    public:
        static void init(shared_ptr<Game>);
        static void renderMenu(shared_ptr<Game>);
        static void drawRect(sf::RenderTarget&, sf::RectangleShape, std::vector<int>, float);
        static void fillText(sf::RenderTarget&, sf::Text, sf::String, std::vector<int>);
        static void drawImage(sf::RenderTarget&, sf::Sprite, sf::Texture, std::vector<int>);
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
        void loadImage();
        void init(shared_ptr<Game>);
        void run(shared_ptr<Game>);
        void handleInput(shared_ptr<Game>);
        void handleScene(shared_ptr<Game>);
};
