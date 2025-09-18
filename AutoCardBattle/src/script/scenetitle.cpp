#include "general.hpp"
#include "decl.hpp"

void SceneTitle::loop(shared_ptr<Game> game) {
    SceneTitle::render(game);
}

void SceneTitle::render(shared_ptr<Game> game) {
    game->window.clear(sf::Color::White);
    game->rTmpRect.setOutlineColor(sf::Color::Black);
    game->rTmpRect.setOutlineThickness(2.0f);
    game->rTmpText.setCharacterSize(32);
    game->rTmpText.setFillColor(sf::Color::Black);
    Render::fillTextUI(game->window, game->rTmpText, "Auto Card Battle", UITitle["text_title"]);
    Render::strokeRectUI(game->window, game->rTmpRect, UITitle["button_start"]);
    Render::fillTextUI(game->window, game->rTmpText, "Start Game", UITitle["text_start"]);
    Render::strokeRectUI(game->window, game->rTmpRect, UITitle["button_collection"]);
    Render::fillTextUI(game->window, game->rTmpText, "Collection", UITitle["text_collection"]);
    game->window.display();
}

void SceneTitle::mouseUp(shared_ptr<Game> game, sf::Vector2f pos) {
    if (pointInsideRectUI(pos, UITitle["button_start"])) {
        game->scene = "game";
    }
}