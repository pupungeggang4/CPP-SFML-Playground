#include "general.hpp"
#include "decl.hpp"

void Render::init(shared_ptr<Game> game) {
    game->rRect.setOutlineColor(sf::Color::Black);
    game->rRect.setOutlineThickness(2.0f);
    game->rText.setCharacterSize(32);
    game->rText.setFillColor(sf::Color::Black);
}

void Render::drawRect(sf::RenderTarget& rt, sf::RectangleShape r, std::vector<int> rect, float thickness) {
    r.setOutlineThickness(thickness);
    r.setPosition({float(rect[0]), float(rect[1])});
    r.setSize({float(rect[2]), float(rect[3])});
    rt.draw(r);
}

void Render::fillText(sf::RenderTarget& rt, sf::Text t, sf::String text, std::vector<int> pos) {
    t.setString(text);
    t.setPosition({float(pos[0]), float(pos[1])});
    rt.draw(t);
}

void Render::drawTexture(sf::RenderTarget& rt, sf::Sprite sprite, sf::Texture tex, std::vector<int> pos) {
    sprite.setTexture(tex, true);
    sprite.setPosition({float(pos[0]), float(pos[1])});
    rt.draw(sprite);
}
