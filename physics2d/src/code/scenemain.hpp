#pragma once
#include "general.hpp"
#include "scene.hpp"

class Game;

class SceneMain : public Scene {
    public:
        sf::Texture tempTex = sf::Texture();
        sf::Font tempFont = sf::Font();
        sf::Sprite iconCoin = sf::Sprite(tempTex); 
        sf::Text textCoin = sf::Text(tempFont);
        SceneMain();
        void loop(shared_ptr<Game>);
        void render(shared_ptr<Game>);
        void keyDown(shared_ptr<Game>, int);
        void keyUp(shared_ptr<Game>, int);
};
