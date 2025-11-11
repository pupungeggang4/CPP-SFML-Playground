#pragma once
#include "general.hpp"

class Scene;
class Village;
class Field;

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

        std::string state = "";
        bool menu = false;
        int selectedTitle = 0, selectedMenuVillage = 0, selectedAdventureConfirm = 0, selectedMenuBattle = 0, selectedAdventureStart = 0;
        float frameCurrent = 0, framePrevious = 0, delta = 0.016;
        std::string lang = "en";
        std::unordered_map<std::string, sf::String> locale;
        std::unordered_map<std::string, bool> keyPressed = {
            {"left", false}, {"right", false}, {"up", false}, {"down", false}
        };

        shared_ptr<Scene> scene;
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