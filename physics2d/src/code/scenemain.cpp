#include "scenemain.hpp"

void SceneMain::loop(shared_ptr<Game> game) {
    render(game);
}

void SceneMain::render(shared_ptr<Game> game) {
    game->window.clear(sf::Color::White);
}