#include "game.hpp"
#include "res.hpp"
#include "entity.hpp"

FieldPlayer::FieldPlayer() : Entity() {
    sprite.setTexture(Res::texture->at("player"), true);
    rect.size = {80, 80};
    coin = 0;
}

void FieldPlayer::handleTick(shared_ptr<Game> game) {
    velocity.x = 0;
    if (game->keyPressed["left"]) {
        velocity.x -= speed;
    }
    if (game->keyPressed["right"]) {
        velocity.x += speed;
    }
    rect.position.x += velocity.x * game->delta;
    handleCollideX(game);
    if (velocity.y < terminalSpeed) {
        velocity.y += gravity * game->delta;
    }
    rect.position.y += velocity.y * game->delta;
    handleFall(game);
    handleCollideUp(game);
}

void FieldPlayer::jump() {
    velocity.y = jumpPower;
}

void FieldPlayer::render(shared_ptr<Game> game) {
    sprite.setPosition(rect.position - rect.size / 2.0f);
    game->window.draw(sprite);
}
