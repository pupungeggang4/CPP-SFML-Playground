#include "general.hpp"
#include "decl.hpp"

void SceneCollection::loop(shared_ptr<Game> game) {
    render(game);
}

void SceneCollection::render(shared_ptr<Game> game) {
    game->window.clear(sf::Color::White);
    game->window.display();
}

void SceneCollection::mouseUp(shared_ptr<Game> game, sf::Vector2f pos) {

}
