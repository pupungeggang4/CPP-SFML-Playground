#include "res.hpp"

shared_ptr<sf::Font> Res::neodgm = make_shared<sf::Font>("font/neodgm.ttf");
shared_ptr<std::unordered_map<std::string, sf::Texture>> Res::texture = make_shared<std::unordered_map<std::string, sf::Texture>>();

void Res::loadImage() {
    Res::neodgm->setSmooth(false);
    Res::texture->emplace("empty", sf::Texture());
    Res::texture->emplace("coin", sf::Texture("image/coin.png"));
    Res::texture->emplace("sprite_coin", sf::Texture("image/spritecoin.png"));
    Res::texture->emplace("player", sf::Texture("image/player.png"));
    Res::texture->emplace("stone", sf::Texture("image/stone.png"));
    Res::texture->emplace("platform", sf::Texture("image/platform.png"));
    Res::texture->at("stone").setRepeated(true);
}