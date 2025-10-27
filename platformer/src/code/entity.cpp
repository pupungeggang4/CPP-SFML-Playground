#include "general.hpp"
#include "decl.hpp"

Entity::Entity(shared_ptr<Game> game) {
}

void Entity::render(shared_ptr<Game> game) {
    shared_ptr<Field> field = game->field;

    frameTime += 0.016;
    frameCurrent = int(frameTime / frameInterval) % frames;
    //std::cout << game->delta << std::endl;

    rTex.clear(sf::Color::Transparent);
    sprite.setTextureRect(frameCoord[frameCurrent]);
    rTex.draw(sprite);
    rTex.display();

    Render::drawCenterCam(game->window, spriteOut, rect, field->cam);
}

void Entity::handleTick(shared_ptr<Game> game) {

}

Coin::Coin(shared_ptr<Game> game) : Entity(game) {
    frameTime = 0; frameInterval = 0.2; frameCurrent = 0; frames = 4;
    frameCoord = {
        {{0, 0}, {40, 40}},
        {{40, 0}, {40, 40}},
        {{80, 0}, {40, 40}},
        {{120, 0}, {40, 40}}
    };
    rTex = sf::RenderTexture({40, 40});
    rect = sf::FloatRect({0, 0}, {40, 40});

    sprite.setTexture(game->tex["coin"]);
    const sf::Texture& t = rTex.getTexture();
    spriteOut.setTexture(t, true);
}

void Coin::render(shared_ptr<Game> game) {
    Entity::render(game);
}

void Coin::handleTick(shared_ptr<Game> game) {
    shared_ptr<Field> field = game->field;
    shared_ptr<FieldPlayer> player = game->field->player;

    if ((rect.position - player->rect.position).length() < 60) {
        player->coin += 1;
        field->entityList.erase(std::find(field->entityList.begin(), field->entityList.end(), field->entityCurrent));
    }
}

FieldPlayer::FieldPlayer(shared_ptr<Game> game) : Entity(game) {
    sprite.setTexture(game->image["player"], true);
    const sf::Texture& t = rTex.getTexture();
    spriteOut.setTexture(t, true);
}

void FieldPlayer::handleTick(shared_ptr<Game> game) {
    if (game->keyPressed["left"]) {
        rect.position.x -= 320 * game->delta;
    }
    if (game->keyPressed["right"]) {
        rect.position.x += 320 * game->delta;
    }
}

void FieldPlayer::render(shared_ptr<Game> game) {
    shared_ptr<Field> field = game->field;

    rTex.clear(sf::Color::Transparent);
    sprite.setTexture(game->image["player"], true);
    rTex.draw(sprite);
    rTex.display();

    Render::drawCenterCam(game->window, spriteOut, rect, field->cam);
}