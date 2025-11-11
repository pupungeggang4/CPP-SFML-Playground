#include "res.hpp"

shared_ptr<std::unordered_map<std::string, sf::Texture>> Res::img = make_shared<std::unordered_map<std::string, sf::Texture>>();