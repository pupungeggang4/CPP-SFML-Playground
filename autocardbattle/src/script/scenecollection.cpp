#include "general.hpp"
#include "decl.hpp"

void SceneCollection::loop(shared_ptr<Game> game) {
    render(game);
}

void SceneCollection::render(shared_ptr<Game> game) {
    game->window.clear(sf::Color::White);
    Render::init(game);
    Render::drawRect(game->window, game->rRect, UI::collection["button_back"], 2);
    game->window.display();
}

void SceneCollection::mouseUp(shared_ptr<Game> game, sf::Vector2f pos) {
    if (Func::pointInsideRectUI(pos, UI::collection["button_back"])) {
        game->scene = "title";
    }
}
