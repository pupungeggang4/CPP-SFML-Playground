#include "general.hpp"
#include "decl.hpp"

void SceneField::loop(shared_ptr<Game> game) {
    render(game);
}

void SceneField::render(shared_ptr<Game> game) {
    game->window.clear(sf::Color::White);
    
    game->window.display();
}

void SceneField::keyDown(shared_ptr<Game> game, int key) {

}

void SceneField::keyUp(shared_ptr<Game> game, int key) {

}