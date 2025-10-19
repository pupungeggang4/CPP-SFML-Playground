#include "general.hpp"
#include "decl.hpp"

void SceneReady::loop(shared_ptr<Game> game) {
    render(game);
}

void SceneReady::render(shared_ptr<Game> game) {
    game->window.clear(sf::Color::White);
    Render::init(game);
    Render::drawRect(game->window, game->rRect, UI::ready["button_back"], 2);
    game->window.display();
}

void SceneReady::mouseUp(shared_ptr<Game> game, sf::Vector2f pos) {
    if (Func::pointInsideRectUI(pos, UI::ready["button_back"])) {
        game->scene = "title";
    }
}
