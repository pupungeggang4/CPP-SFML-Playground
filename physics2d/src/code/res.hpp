#pragma once
#include "general.hpp"

class Res {
    public:
        static shared_ptr<sf::Font> neodgm;
        static shared_ptr<std::unordered_map<std::string, sf::Texture>> texture;

        static void loadImage();
};