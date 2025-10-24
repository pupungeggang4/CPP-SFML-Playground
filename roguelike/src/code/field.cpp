#include "general.hpp"
#include "decl.hpp"

Field::Field() {
    player = make_shared<FieldPlayer>();
}

void Field::handleTick(shared_ptr<Game> game) {
    player->handleTick(game);
}

void Field::render(shared_ptr<Game> game) {
    player->render(game);
}

Entity::Entity() {

}

void Entity::handleTick(shared_ptr<Game> game) {

}

void Entity::render(shared_ptr<Game> game) {

}

Unit::Unit() {

}

FieldPlayer::FieldPlayer() {
    
}

void FieldPlayer::render(shared_ptr<Game> game) {
    rt.clear(sf::Color::Transparent);
    Render::drawTexture(rt, sprite, game->tex["player"], {0, 0});
    rt.display();

    const sf::Texture& tmpTex = rt.getTexture();
    spriteOut.setTexture(tmpTex, true);
    spriteOut.setPosition(rect.position);
    game->window.draw(spriteOut);
}
