#include "fieldplayer.hpp"
#include "game.hpp"
#include "render.hpp"

FieldPlayer::FieldPlayer() {
    rectS.setOutlineColor(sf::Color::Black);
    rectS.setOutlineThickness(2);
    rectS.setPosition(rect.position);
}

void FieldPlayer::handleTick(shared_ptr<Game> game) {
    if (game->keyPressed["left"]) {
        rect.position.x -= speed * game->delta;
    }
    if (game->keyPressed["right"]) {
        rect.position.x += speed * game->delta;
    }
}

void FieldPlayer::render(shared_ptr<Game> game) {
    Render::drawRectAtCenter(game->window, rectS, rect);
}