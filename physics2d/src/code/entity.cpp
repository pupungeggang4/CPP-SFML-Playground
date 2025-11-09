#include "entity.hpp"

#include "res.hpp"
#include "field.hpp"
#include "fieldplayer.hpp"
#include "render.hpp"
#include "game.hpp"

Entity::Entity() : sprite(Res::texture->at("empty")) {
    
}

void Entity::handleTick(shared_ptr<Game> game) {
    
}

void Entity::render(shared_ptr<Game> game) {

}

Coin::Coin() : sprite(Res::texture->at("sprite_coin")) {
    rect.position.x = 400.0f;
}

void Coin::render(shared_ptr<Game> game) {
    frameTime += game->delta;
    frameCurrent = int(frameTime / frameInterval) % frames;
    sprite.setTextureRect(frameCoord[frameCurrent]);
    sprite.setPosition(rect.position - rect.size / 2.0f);
    game->window.draw(sprite);
}

void Coin::handleTick(shared_ptr<Game> game) {
    shared_ptr<Field> field = game->field;
    shared_ptr<FieldPlayer> player = game->field->player;
    if ((rect.position - player->rect.position).length() < 60.0f) {
        player->coin += 1;
        field->entityList.erase(std::find(field->entityList.begin(), field->entityList.end(), field->currentEntity));
    }
}

Wall::Wall() : sprite(Res::texture->at("stone")) {
    sprite.setTextureRect(sf::IntRect(rect));
}

void Wall::render(shared_ptr<Game> game) {
    sprite.setPosition(rect.position - rect.size / 2.0f);
    game->window.draw(sprite);
}

Platform::Platform() : sprite(Res::texture->at("platform")) {

}

void Platform::render(shared_ptr<Game> game) {
    sprite.setPosition(rect.position - rect.size / 2.0f);
    game->window.draw(sprite);
}