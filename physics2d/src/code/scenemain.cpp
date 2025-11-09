#include "scenemain.hpp"
#include "field.hpp"
#include "game.hpp"

void SceneMain::loop(shared_ptr<Game> game) {
    game->field->handleTick(game);
    render(game);
}

void SceneMain::render(shared_ptr<Game> game) {
    game->window.clear(sf::Color::White);
    game->window.setView(game->field->view);
    game->field->render(game);
}