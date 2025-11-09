#include "entity.hpp"
#include "res.hpp"
#include "render.hpp"
#include "game.hpp"

Entity::Entity() {
    
}

void Entity::handleTick(shared_ptr<Game> game) {

}

void Entity::render(shared_ptr<Game> game) {
    
}

Coin::Coin() : Entity() {
    texture = sf::Texture(Res::texture->at("sprite_coin"));
}

void Coin::render(shared_ptr<Game> game) {
    frameTime += game->delta;
    frameCurrent = int(frameTime / frameInterval) % frames;
    sprite.setTextureRect(frameCoord[frameCurrent]);
    sprite.setPosition(rect.position - rect.size / 2.0f);
    game->window.draw(sprite);
}

Wall::Wall() : Entity() {
    rectS.setOutlineColor(sf::Color::Black);
    rectS.setOutlineThickness(2);
    rectS.setPosition(rect.position);
}

void Wall::render(shared_ptr<Game> game) {
    Render::drawRectAtCenter(game->window, rectS, rect);
}

Platform::Platform() : Entity() {
    rectS.setOutlineColor(sf::Color::Black);
    rectS.setOutlineThickness(2);
    rectS.setPosition(rect.position);
}

void Platform::render(shared_ptr<Game> game) {
    Render::drawRectAtCenter(game->window, rectS, rect);
}