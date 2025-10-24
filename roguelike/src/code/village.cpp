#include "general.hpp"
#include "decl.hpp"

Village::Village() {
    player = make_shared<VillagePlayer>();
    portalBattle = make_shared<VillagePortal>();
}

void Village::handleTick(shared_ptr<Game> game) {
    player->handleTick(game);
}

void Village::render(shared_ptr<Game> game) {
    player->render(game);
    portalBattle->render(game);
}

VillagePlayer::VillagePlayer() {

}

void VillagePlayer::handleTick(shared_ptr<Game> game) {
    move(game);
}

void VillagePlayer::move(shared_ptr<Game> game) {
    sf::Vector2f velocity = {0, 0};
    sf::Vector2f tempPosition = {rect.position.x, rect.position.y};
    bool xPressed = false;
    bool yPressed = false;

    if (game->keyPressed["left"] == true) {
        xPressed = true;
        velocity.x -= 1;
    }
    if (game->keyPressed["right"] == true) {
        xPressed = true;
        velocity.x += 1;
    }
    if (game->keyPressed["up"] == true) {
        yPressed = true;
        velocity.y -= 1;
    }
    if (game->keyPressed["down"] == true) {
        yPressed = true;
        velocity.y += 1;
    }

    if (xPressed && yPressed) {
        velocity *= 0.7f;
    }

    tempPosition.x += velocity.x * speed * game->delta;
    tempPosition.y += velocity.y * speed * game->delta;

    rect.position.x = tempPosition.x;
    rect.position.y = tempPosition.y;
}

void VillagePlayer::interact(shared_ptr<Game> game) {
    auto village = game->village;
    if ((village->portalBattle->rect.position - rect.position).length() < 80) {
        game->state = "adventure_confirm";
        game->selectedAdventureConfirm = 0;
    }
}

void VillagePlayer::render(shared_ptr<Game> game) {
    rt.clear(sf::Color::Transparent);
    sprite.setTexture(game->tex["player"], true);
    rt.draw(sprite);
    rt.display();

    const sf::Texture& tmpTex = sprite.getTexture();
    spriteOut.setTexture(tmpTex, true);
    Render::drawCenterCam(game->window, spriteOut, rect, game->village->camera);
}

VillagePortal::VillagePortal() {

}

void VillagePortal::render(shared_ptr<Game> game) {
    rt.clear(sf::Color::Transparent);
    sprite.setTexture(game->tex["portal"], true);
    rt.draw(sprite);
    rt.display();

    const sf::Texture& tmpTex = sprite.getTexture();
    spriteOut.setTexture(tmpTex, true);
    Render::drawCenterCam(game->window, spriteOut, rect, game->village->camera);
}
