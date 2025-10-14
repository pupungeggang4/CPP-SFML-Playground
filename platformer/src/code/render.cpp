#include "general.hpp"
#include "decl.hpp"

void Render::init(shared_ptr<Game> game) {
    game->rRect.setOutlineColor(sf::Color::Black);
    game->rRect.setOutlineThickness(2);
    game->rText.setFillColor(sf::Color::Black);
}

void Render::strokeRect(sf::RenderWindow& window, sf::RectangleShape rRect, std::vector<int> pos) {
    rRect.setPosition({float(pos[0]), float(pos[1])});
    rRect.setSize({float(pos[2]), float(pos[3])});
    window.draw(rRect);
}

void Render::fillText(sf::RenderWindow& window, sf::Text rText, std::string text, std::vector<int> pos) {
    rText.setString(text);
    rText.setPosition({float(pos[0]), float(pos[1])});
    window.draw(rText);
}

void Render::drawImage(sf::RenderWindow& window, sf::Sprite sprite, sf::Texture texture, std::vector<int> pos) {
    sprite.setTexture(texture, true);
    sprite.setPosition({float(pos[0]), float(pos[1])});
    window.draw(sprite);
}

/*
void Render::strokeRectUI(sf::RenderWindow& window, sf::RectangleShape rRect, UICoord c) {
    auto coord = std::get<std::vector<int>>(c);
    rRect.setPosition({float(coord[0]), float(coord[1])});
    rRect.setSize({float(coord[2]), float(coord[3])});
    window.draw(rRect);
}
*/
