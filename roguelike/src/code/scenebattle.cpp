#include "general.hpp"
#include "decl.hpp"

void SceneBattle::loop(shared_ptr<Game> game) {
    render(game);
}

void SceneBattle::render(shared_ptr<Game> game) {
    game->window.clear(sf::Color::White);
    Render::renderInit(game);
    game->window.display();
}

void SceneBattle::keyDown(shared_ptr<Game> game, int key) {
    int alpha = key + 97;
}

void SceneBattle::keyUp(shared_ptr<Game>game, int key) {

}
