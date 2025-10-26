#include "general.hpp"
#include "decl.hpp"

Field::Field() {
    player = make_shared<FieldPlayer>();
    shared_ptr<Entity> e = make_shared<Coin>();
    entityList.push_back(e);
}

void Field::handleTick(shared_ptr<Game> game) {
    shared_ptr<Field> field = game->field;
    player->handleTick(game);

    for (int i = entityList.size() - 1; i >= 0; i--) {
        entityCurrent = entityList[i];
        entityList[i]->handleTick(game);
    }
}

void Field::render(shared_ptr<Game> game) {
    player->render(game);

    for (int i = entityList.size() - 1; i >= 0; i--) {
        entityList[i]->render(game);
    }
}

FieldPlayer::FieldPlayer() {
}

void FieldPlayer::handleTick(shared_ptr<Game> game) {
    if (game->keyPressed["left"]) {
        rect.position.x -= 320 * 0.016;
    }
    if (game->keyPressed["right"]) {
        rect.position.x += 320 * 0.016;
    }
}

void FieldPlayer::render(shared_ptr<Game> game) {
    shared_ptr<Field> field = game->field;
    sprite.setTexture(game->tex["player"]);

    rTex.clear(sf::Color::Transparent);
    Render::drawImage(rTex, sprite, game->tex["player"], {0, 0});
    rTex.display();

    const sf::Texture& t = rTex.getTexture();
    spriteOut.setTexture(t, true);
    Render::drawCenterCam(game->window, spriteOut, rect, field->cam);
}
