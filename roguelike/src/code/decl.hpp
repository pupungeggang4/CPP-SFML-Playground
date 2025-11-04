#pragma once
#include "general.hpp"

class Res;
class UI;
class Locale;

class Adventure;

class Village;
class VillagePlayer;
class VillageEntity;
class VillagePortal;

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

class Res {
    public:
        static shared_ptr<std::unordered_map<std::string, sf::Texture>> img;
};

class UI {
    public:
        static std::unordered_map<std::string, std::vector<int>> title;
        static std::vector<std::vector<int>> titleArrow;
        static std::unordered_map<std::string, std::vector<int>> village;
        static std::unordered_map<std::string, std::vector<int>> menuVillage;
        static std::vector<std::vector<int>> menuVillageArrow;
        static std::unordered_map<std::string, std::vector<int>> adventureConfirm;
        static std::vector<std::vector<int>> adventureConfirmArrow;

        static std::unordered_map<std::string, UICoord> window;
        static std::vector<std::vector<int>> adventureStartArrow;
        static std::unordered_map<std::string, std::vector<int>> battle;
        static std::unordered_map<std::string, std::vector<int>> menuBattle;
        static std::vector<std::vector<int>> menuBattleArrow;
};

class Locale {
    public:
        static std::unordered_map<std::string, std::unordered_map<std::string, sf::String>> data;
};

class Village {
    public:
        sf::FloatRect camera = {{0, 0}, {1280, 720}};
        shared_ptr<VillagePlayer> player;
        shared_ptr<VillagePortal> portalBattle;

        Village(shared_ptr<Game>);
        void handleTick(shared_ptr<Game>);
        void render(shared_ptr<Game>);
};

class VillagePlayer {
    public:
        sf::FloatRect rect = {{0, 0}, {80, 80}};
        sf::RenderTexture rt;
        sf::Texture t;
        sf::Sprite sprite = sf::Sprite(t), spriteOut = sf::Sprite(t);

        float speed = 320.0f;

        VillagePlayer(shared_ptr<Game>);
        void handleTick(shared_ptr<Game>);
        void render(shared_ptr<Game>);
        void move(shared_ptr<Game>);
        void interact(shared_ptr<Game>);
};

class VillagePortal {
    public:
        sf::FloatRect rect = {{0, -200}, {80, 80}};
        sf::RenderTexture rt;
        sf::Texture t;
        sf::Sprite sprite = sf::Sprite(t), spriteOut = sf::Sprite(t);

        VillagePortal(shared_ptr<Game>);
        void render(shared_ptr<Game>);
};

class Field {
    public:
        sf::FloatRect camera = {{0, 0}, {1280, 720}};
        shared_ptr<FieldPlayer> player;
        std::vector<shared_ptr<Drop>> drop = {};
        shared_ptr<Drop> dropCurrent;
    
        Field(shared_ptr<Game>);
        void handleTick(shared_ptr<Game>);
        void render(shared_ptr<Game>);
};

class Entity {
    public:
        sf::FloatRect rect = {{0, 0}, {40, 40}};
        sf::Texture t = sf::Texture();
        sf::RenderTexture rt = sf::RenderTexture({80, 80});
        sf::Sprite sprite = sf::Sprite(t), spriteOut = sf::Sprite(t);

        Entity(shared_ptr<Game>);
        void handleTick(shared_ptr<Game>);
        void render(shared_ptr<Game>);
};

class Unit : public Entity {
    public:
        Unit(shared_ptr<Game>);
        //void handleTick(shared_ptr<Game>);
        //void render(shared_ptr<Game>)
};

class FieldPlayer : public Unit {
    public:
        float speed = 320.0f;
        int level = 1, exp = 0, expMax = 20, gold = 50;
        float energy = 0.0f, energyMax = 8.0f, life = 120.0f, lifeMax = 120.0f;
        FieldPlayer(shared_ptr<Game>);
        void handleTick(shared_ptr<Game>);
        void move(shared_ptr<Game>);
        void render(shared_ptr<Game>);
};

class Drop : public Entity {
    public:
        std::string type;
        int amount;
        Drop(shared_ptr<Game>, std::string, int);
        void handleTick(shared_ptr<Game>);
        void render(shared_ptr<Game>);
};

class Projectile : public Entity {
    public:
};

class Render {
    public:
        static void renderInit(shared_ptr<Game>);
        static void renderMenuVillage(shared_ptr<Game>);
        static void renderAdventureConfirm(shared_ptr<Game>);
        static void renderAdventureStart(shared_ptr<Game>);
        static void renderBattleUIUpper(shared_ptr<Game>);
        static void renderMenuBattle(shared_ptr<Game>);
        static void fillText(sf::RenderTarget&, sf::Text&, sf::String, std::vector<int>);
        static void drawRect(sf::RenderTarget&, sf::RectangleShape&, std::vector<int>, float);
        static void drawTexture(sf::RenderTarget&, sf::Sprite&, sf::Texture&, std::vector<int>);
        static void drawCenterCam(sf::RenderTarget&, sf::Sprite&, sf::FloatRect, sf::FloatRect);
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
        sf::Clock clock = sf::Clock();

        std::string scene = "title", state = "";
        bool menu = false;
        int selectedTitle = 0, selectedMenuVillage = 0, selectedAdventureConfirm = 0, selectedMenuBattle = 0, selectedAdventureStart = 0;
        float frameCurrent = 0, framePrevious = 0, delta = 0.016;
        std::string lang = "en";
        std::unordered_map<std::string, sf::String> locale;
        std::unordered_map<std::string, bool> keyPressed = {
            {"left", false}, {"right", false}, {"up", false}, {"down", false}
        };

        shared_ptr<Field> field;
        shared_ptr<Village> village;

        Game();
        void init(shared_ptr<Game>);
        void loadFont();
        void loadImage();
        void run(shared_ptr<Game>);
        void handleScene(shared_ptr<Game>);
        void handleInput(shared_ptr<Game>);
};
