#pragma once
#include "general.hpp"

class Game;

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