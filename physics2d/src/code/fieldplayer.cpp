#include "fieldplayer.hpp"

FieldPlayer::FieldPlayer() : Entity() {
    rectS.setOutlineColor(sf::Color::Black);
    rectS.setOutlineThickness(2);
    rectS.setPosition(rect.position);
}

void FieldPlayer::handleTick(shared_ptr<Game> game) {

}

void FieldPlayer::render(shared_ptr<Game> game) {
    Render::drawAtCenter(game->window, rectS, rect);
}