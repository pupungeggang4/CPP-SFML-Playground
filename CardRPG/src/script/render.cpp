#include "general.hpp"
#include "decl.hpp"

template <typename Game2>
void renderTitle(Game2 game) {
    game->window.clear(sf::Color::Green);
    game->window.display();
}