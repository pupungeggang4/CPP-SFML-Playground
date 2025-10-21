#include "general.hpp"
#include "decl.hpp"

Field::Field(shared_ptr<Game> game) {
    player = make_shared<FieldPlayer>();
    shared_ptr<Entity> e = make_shared<Coin>(game);
    entityList.push_back(e);
}

void Field::handleTick(shared_ptr<Field> field, shared_ptr<Game> game) {
    player->handleTick(field, game);
}

void Field::render(sf::RenderTarget& rt, shared_ptr<Field> field, shared_ptr<Game> game) {
    player->render(rt, field, game);
    entityList[0]->render(rt, field, game);
}

FieldPlayer::FieldPlayer() {
}

void FieldPlayer::handleTick(shared_ptr<Field> field, shared_ptr<Game> game) {
    if (game->keyPressed["left"]) {
        rect.position.x -= 320 * 0.016;
    }
    if (game->keyPressed["right"]) {
        rect.position.x += 320 * 0.016;
    }
}

void FieldPlayer::render(sf::RenderTarget& rt, shared_ptr<Field> field, shared_ptr<Game> game) {
    rTex.clear(sf::Color::Transparent);
    Render::drawImage(rTex, sprite, game->tex["player"], {0, 0});
    rTex.display();
    const sf::Texture& t = rTex.getTexture();
    spriteOut.setTexture(t, true);

    Render::drawCenterCam(rt, spriteOut, rect, field->cam);
}
