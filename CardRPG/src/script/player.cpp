#include "general.hpp"
#include "decl.hpp"

Player::Player() {
    rect = {{0.0f, 0.0f}, {80.0f, 80.0f}};
}

void Player::move(shared_ptr<Game> game) {
    if (game->keyPressed["up"] == true) {
        rect.position.y -= speed / 60.0f;
    }
    if (game->keyPressed["left"] == true) {
        rect.position.x -= speed / 60.0f;
    }
    if (game->keyPressed["down"] == true) {
        rect.position.y += speed / 60.0f;
    }
    if (game->keyPressed["right"] == true) {
        rect.position.x += speed / 60.0f;
    }
}