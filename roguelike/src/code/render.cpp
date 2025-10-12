#pragma once
#include "general.hpp"
#include "decl.hpp"

void Render::fillText(sf::RenderWindow& window, sf::Text rText, std::string text, std::any pos) {
    std::vector<int> p = (std::vector<int>)pos;
    rText.setString(text);
    rText.setPosition({float(p[0]), float(p[1])});
    window.draw(rText);
}

void Render::strokeRect(sf::RenderWindow& window, sf::RectangleShape rRect, std::any rect) {
    std::vector<int> r = (std::vector<int>)rect;
    rRect.setPosition({float(rect[0]), float(rect[1])});
    rRect.setSize({float(rect[2]), float(rect[3])});
    window.draw(rRect);
}

void Render::drawTexture(sf::RenderWindow& window, sf::Texture texture, sf::Sprite sprite, std::any pos) {
    std::vector<int> r = (std::vector<int>)tect;
    sprite.setTexture(texture);
    sprite.setPosition({float(pos[0]), float(pos[1])});
    window.draw(sprite);
}