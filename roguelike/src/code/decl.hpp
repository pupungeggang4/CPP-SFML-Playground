#pragma once
#include "general.hpp"

class UI;
class Locale;

class Adventure;
class Field;
class Entity;
class FieldPlayer;
class Projectile;
class Drop;
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
        static std::unordered_map<std::string, std::vector<int>> menuVillage;
        static std::vector<std::vector<int>> menuVillageArrow;
};

class Locale {
    public:
        static std::unordered_map<std::string, std::unordered_map<std::string, sf::String>> data;
};

class Field {
    public:
        shared_ptr<FieldPlayer> player;
        std::vector<shared_ptr<Drop>> drop = {};
    
        Field();
        void handleTick(shared_ptr<Game>);
        void render(shared_ptr<Game>);
};

class Entity {
    public:
        sf::FloatRect rect = {{0, 0}, {80, 80}};
        sf::Texture t = sf::Texture();
        sf::RenderTexture rt = sf::RenderTexture({80, 80});
        sf::Sprite sprite = sf::Sprite(t), spriteOut = sf::Sprite(t);

        Entity();
        void handleTick(shared_ptr<Game>);
        void render(shared_ptr<Game>);
};

class Unit : public Entity {
    public:
        Unit();
        //void handleTick(shared_ptr<Game>);
        //void render(shared_ptr<Game>)
};

class FieldPlayer : public Unit {
    public:
        FieldPlayer();
        //void handleTick(shared_ptr<Game>);
        void render(shared_ptr<Game>);
};

class Drop : public Entity {
    public:
        std::string type;
        int amount;
        Drop();
        //void handleTick(shared_ptr<Game>);
        //void render(shared_ptr<Game>);
};

class Projectile : public Entity {
    public:
};

class Render {
    public:
        static void renderInit(shared_ptr<Game>);
        static void renderMenu(shared_ptr<Game>);
        static void fillText(sf::RenderTarget&, sf::Text, sf::String, std::vector<int>);
        static void drawRect(sf::RenderTarget&, sf::RectangleShape, std::vector<int>, float);
        static void drawTexture(sf::RenderTarget&, sf::Sprite, sf::Texture, std::vector<int>);
};

class Func {
    public:
        static bool pointInsideRectUI(sf::Vector2i, sf::IntRect);
};

class SceneTitle {
    public:
        static void loop(shared_ptr<Game>);
        static void render(shared_ptr<Game>);
        static void keyDown(shared_ptr<Game>, int);
        static void keyUp(shared_ptr<Game>, int);
};

class SceneVillage {
    public:
        static void loop(shared_ptr<Game>);
        static void render(shared_ptr<Game>);
        static void keyDown(shared_ptr<Game>, int);
        static void keyUp(shared_ptr<Game>, int);
};

class SceneBattle {
    public:
        static void loop(shared_ptr<Game>);
        static void render(shared_ptr<Game>);
        static void keyDown(shared_ptr<Game>, int);
        static void keyUp(shared_ptr<Game>, int);
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
        int selectedTitle = 0, selectedMenuVillage = 0, selectedAdventureConfirm = 0, selectedMenuBattle = 0;
        std::string lang = "en";
        std::unordered_map<std::string, sf::String> locale;

        shared_ptr<Field> field;

        Game();
        void init(shared_ptr<Game>);
        void loadFont();
        void loadImage();
        void run(shared_ptr<Game>);
        void handleScene(shared_ptr<Game>);
        void handleInput(shared_ptr<Game>);
};
