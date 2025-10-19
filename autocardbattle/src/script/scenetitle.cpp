#include "general.hpp"
#include "decl.hpp"

void SceneTitle::loop(shared_ptr<Game> game) {
    render(game);
}

void SceneTitle::render(shared_ptr<Game> game) {
    game->window.clear(sf::Color::White);
    game->rTmpRect.setOutlineColor(sf::Color::Black);
    game->rTmpRect.setOutlineThickness(2.0f);
    game->rTmpText.setCharacterSize(32);
    game->rTmpText.setFillColor(sf::Color::Black);
    Render::fillText(game->window, game->rTmpText, "Auto Card Battle", UI::title["text_title"]);
    Render::drawRect(game->window, game->rTmpRect, UI::title["button_start"], 2);
    Render::fillText(game->window, game->rTmpText, "Start Game", UI::title["text_start"]);
    Render::drawRect(game->window, game->rTmpRect, UI::title["button_collection"], 2);
    Render::fillText(game->window, game->rTmpText, "Collection", UI::title["text_collection"]);
    Render::drawRect(game->window, game->rTmpRect, UI::title["button_exit"], 2);
    Render::fillText(game->window, game->rTmpText, "Exit", UI::title["text_exit"]);
    game->window.display();
}

void SceneTitle::mouseUp(shared_ptr<Game> game, sf::Vector2f pos) {
    if (Func::pointInsideRectUI(pos, UI::title["button_start"])) {
        game->scene = "ready";
    } else if (Func::pointInsideRectUI(pos, UI::title["button_collection"])) {
        game->scene = "collection";
    } else if (Func::pointInsideRectUI(pos, UI::title["button_exit"])) {
        game->window.close();
    }
}
