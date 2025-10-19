#include "general.hpp"
#include "decl.hpp"

void SceneReady::loop(shared_ptr<Game> game) {
    render(game);
}

void SceneReady::render(shared_ptr<Game> game) {
    game->window.clear(sf::Color::White);
    game->window.display();
}

void SceneReady::mouseUp(shared_ptr<Game> game, sf::Vector2f pos) {

}
