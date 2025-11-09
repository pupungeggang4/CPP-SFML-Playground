#include "fieldplayer.hpp"
#include "game.hpp"
#include "render.hpp"
#include "res.hpp"

FieldPlayer::FieldPlayer() : sprite(Res::texture->at("player")) {
    coin = 0;
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
    sprite.setPosition(rect.position - rect.size / 2.0f);
    game->window.draw(sprite);
}