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
