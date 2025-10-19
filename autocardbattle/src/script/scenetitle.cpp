#include "general.hpp"
#include "decl.hpp"

void SceneTitle::loop(shared_ptr<Game> game) {
    render(game);
}

void SceneTitle::render(shared_ptr<Game> game) {
    game->window.clear(sf::Color::White);
    Render::init(game);
    Render::fillText(game->window, game->rText, "Auto Card Battle", UI::title["text_title"]);
    Render::drawRect(game->window, game->rRect, UI::title["button_start"], 2);
    Render::fillText(game->window, game->rText, "Start Game", UI::title["text_start"]);
    Render::drawRect(game->window, game->rRect, UI::title["button_collection"], 2);
    Render::fillText(game->window, game->rText, "Collection", UI::title["text_collection"]);
    Render::drawRect(game->window, game->rRect, UI::title["button_exit"], 2);
    Render::fillText(game->window, game->rText, "Exit", UI::title["text_exit"]);
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
