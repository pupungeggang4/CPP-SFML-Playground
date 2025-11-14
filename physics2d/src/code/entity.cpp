#include "entity.hpp"

#include "res.hpp"
#include "field.hpp"
#include "physics.hpp"
#include "render.hpp"
#include "game.hpp"

Entity::Entity() : sprite(Res::texture->at("empty")) {
    
}

void Entity::handleTick(shared_ptr<Game> game) {
    
}

void Entity::render(shared_ptr<Game> game) {

}

void Entity::handleCollideX(shared_ptr<Game> game) {
    shared_ptr<Field> field = game->field;
    for (int i = 0; i < field->entityList.size(); i++) {
        shared_ptr<Entity> entity = field->entityList[i];
        if (shared_from_this() != entity && (entity->solid == true)) {
            float left = Physics::checkCollideLeft(entity->rect, shared_from_this()->rect);
            if (left > 0) {
                shared_from_this()->rect.position.x -= left;
            }
            float right = Physics::checkCollideRight(entity->rect, shared_from_this()->rect);
            if (right > 0) {
                shared_from_this()->rect.position.x += right;
            }
        }
    }
}

void Entity::handleFall(shared_ptr<Game> game) {
shared_ptr<Field> field = game->field;
    for (int i = 0; i < field->entityList.size(); i++) {
        shared_ptr<Entity> entity = field->entityList[i];
        if (shared_from_this() != entity && (entity->solid == true)) {
            float up = Physics::checkCollideUp(entity->rect, shared_from_this()->rect);
            if (up > 0) {
                shared_from_this()->rect.position.y -= up;
                shared_from_this()->velocity.y = 0;
            }
        }
    }
}

void Entity::handleCollideUp(shared_ptr<Game> game) {
    shared_ptr<Field> field = game->field;
    for (int i = 0; i < field->entityList.size(); i++) {
        shared_ptr<Entity> entity = field->entityList[i];
        if (shared_from_this() != entity && entity->solid == true) {
            float down = Physics::checkCollideDown(entity->rect, shared_from_this()->rect);
            if (down > 0) {
                shared_from_this()->rect.position.y += down;
                shared_from_this()->velocity.y = 0;
            }
        }
    }
}

Coin::Coin() : Entity() {
    sprite.setTexture(Res::texture->at("sprite_coin"), true);
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
        field->entityList.erase(std::find(field->entityList.begin(), field->entityList.end(), shared_from_this()));
    }
}

Wall::Wall() : Entity() {
    sprite.setTexture(Res::texture->at("stone"), true);
    solid = true; floor = true; fall = false;
}

void Wall::render(shared_ptr<Game> game) {
    sprite.setPosition(rect.position - rect.size / 2.0f);
    game->window.draw(sprite);
}

Platform::Platform() : Entity() {
    sprite.setTexture(Res::texture->at("platform"), true);
    solid = false; floor = true; fall = false;
}

void Platform::render(shared_ptr<Game> game) {
    sprite.setPosition(rect.position - rect.size / 2.0f);
    game->window.draw(sprite);
}
