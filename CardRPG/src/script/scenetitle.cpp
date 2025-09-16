#include "general.hpp"
#include "decl.hpp"

void loopTitle(shared_ptr<Game> game) {
    game->player->move(game);
    renderTitle(game);
}

void renderTitle(shared_ptr<Game> game) {
    game->window.clear();
    sf::RectangleShape rect;
    rect.setPosition({game->player->rect.position.x, game->player->rect.position.y});
    rect.setSize({game->player->rect.size.x, game->player->rect.size.y});
    game->window.draw(rect);
    game->window.display();
}