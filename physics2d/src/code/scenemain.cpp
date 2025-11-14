#include "scenemain.hpp"
#include "res.hpp"
#include "field.hpp"
#include "entity.hpp"
#include "scene.hpp"
#include "game.hpp"

SceneMain::SceneMain() {
    iconCoin.setTexture(Res::texture->at("coin"), true);
    iconCoin.setPosition({20, 20});
    textCoin.setFont(*Res::neodgm);
    textCoin.setFillColor(sf::Color::Black);
    textCoin.setCharacterSize(32);
    textCoin.setString("");
    textCoin.setPosition({64, 20});
}

void SceneMain::loop(shared_ptr<Game> game) {
    game->field->handleTick(game);
    render(game);
}

void SceneMain::render(shared_ptr<Game> game) {
    game->window.clear(sf::Color::White);
    game->field->render(game);
    game->window.setView(game->UIView);
    game->window.draw(iconCoin);
    textCoin.setString(std::to_string(game->field->player->coin));
    game->window.draw(textCoin);
}

void SceneMain::keyDown(shared_ptr<Game> game, int key) {
    if (key == K_UP) {
        game->field->player->jump();
    }
}

void SceneMain::keyUp(shared_ptr<Game> game, int key) {
}
