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

Coin::Coin() : Entity(), sprite(sf::Sprite(Res::texture->at("sprite_coin"))) {
}

void Coin::render(shared_ptr<Game> game) {
    frameTime += game->delta;
    frameCurrent = int(frameTime / frameInterval) % frames;
    sprite.setTextureRect(frameCoord[frameCurrent]);
    sprite.setPosition(rect.position - rect.size / 2.0f);
    game->window.draw(sprite);
}

Wall::Wall() : Entity(), sprite(sf::Sprite(Res::texture->at("stone"))) {
    rectS.setOutlineColor(sf::Color::Black);
    rectS.setOutlineThickness(2);
    rectS.setPosition(rect.position);
    sprite.setTextureRect(sf::IntRect(rect));
}

void Wall::render(shared_ptr<Game> game) {
    sprite.setPosition(rect.position - rect.size / 2.0f);
    game->window.draw(sprite);
}

Platform::Platform() : Entity() {
    rectS.setOutlineColor(sf::Color::Black);
    rectS.setOutlineThickness(2);
    rectS.setPosition(rect.position);
}

void Platform::render(shared_ptr<Game> game) {
    Render::drawRectAtCenter(game->window, rectS, rect);
}