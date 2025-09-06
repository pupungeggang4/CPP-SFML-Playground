#include "scenefield.hpp"

SceneField::SceneField() {
    
}

void SceneField::loop(shared_ptr<Game> game) {
    render(game);
}

void SceneField::render(shared_ptr<Game> game) {
    game->window.clear(sf::Color::White);
    game->window.display();
}