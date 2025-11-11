#include "res.hpp"

shared_ptr<sf::Font> Res::neodgm = make_shared<sf::Font>("font/neodgm.ttf");
shared_ptr<std::unordered_map<std::string, sf::Texture>> Res::img = make_shared<std::unordered_map<std::string, sf::Texture>>();

void Res::loadFont() {
    Res::neodgm->setSmooth(false);
}

void Res::loadImage() {
    Res::img->emplace("arrow", sf::Texture("image/arrow.png"));
    Res::img->emplace("player", sf::Texture("image/player.png"));
    Res::img->emplace("portal", sf::Texture("image/portal.png"));
    Res::img->emplace("arrow_down", sf::Texture("image/arrowdown.png"));
    Res::img->emplace("exporb", sf::Texture("image/exporb.png"));
    Res::img->emplace("coin", sf::Texture("image/coin.png"));
    Res::img->emplace("life", sf::Texture("image/life.png"));
    Res::img->emplace("energy", sf::Texture("image/energy.png"));
}
