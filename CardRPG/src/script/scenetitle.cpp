#include "general.hpp"
#include "decl.hpp"

void loopTitle(shared_ptr<Game> game) {
    renderTitle(game);
}

void renderTitle(shared_ptr<Game> game) {
    game->window.clear();
    game->window.display();
}