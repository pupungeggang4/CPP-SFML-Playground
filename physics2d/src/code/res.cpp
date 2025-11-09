#include "res.hpp"

sf::Font neodgm = sf::Font("font/neodgm.ttf");
shared_ptr<std::unordered_map<std::string, sf::Texture>> Res::texture = make_shared<std::unordered_map<std::string, sf::Texture>>();

void Res::loadImage() {
    Res::texture->emplace("sprite_coin", sf::Texture("image/spritecoin.png"));
    Res::texture->emplace("player", sf::Texture("image/player.png"));
    Res::texture->emplace("stone", sf::Texture("image/stone.png"));
    Res::texture->at("stone").setRepeated(true);
}