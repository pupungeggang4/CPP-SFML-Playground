#include "general.hpp"
#include "decl.hpp"

void SceneGame::loop(shared_ptr<Game> game) {
    SceneGame::render(game);
}

void SceneGame::render(shared_ptr<Game> game) {
    game->window.clear(sf::Color::White);
    game->window.display();
}