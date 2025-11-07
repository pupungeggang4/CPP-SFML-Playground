#include "res.hpp"

sf::Font neodgm = sf::Font("font/neodgm.ttf");
shared_ptr<std::unordered_map<std::string, sf::Texture>> Res::image = make_shared<std::unordered_map<std::string, sf::Texture>>();