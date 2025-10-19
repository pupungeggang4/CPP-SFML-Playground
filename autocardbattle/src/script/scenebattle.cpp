#include "general.hpp"
#include "decl.hpp"

void SceneBattle::loop(shared_ptr<Game> game) {
    render(game);
}

void SceneBattle::render(shared_ptr<Game> game) {
    game->window.clear(sf::Color::White);
    game->window.display();
}

void SceneBattle::mouseUp(shared_ptr<Game> game, sf::Vector2f pos) {

}
