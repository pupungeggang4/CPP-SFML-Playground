#include "general.hpp"
#include "decl.hpp"

Entity::Entity(shared_ptr<Game> game) {

}

void Entity::render(sf::RenderTarget& rt, shared_ptr<Field> field, shared_ptr<Game> game) {
    drawThis(rt, game->tex["coin"], field, game);
    const sf::Texture& t = rTex.getTexture();
    spriteOut.setTexture(t, true);
    Render::drawCenterCam(rt, spriteOut, rect, field->cam);
}
void Entity::drawThis(sf::RenderTarget& rt, sf::Texture texTarget, shared_ptr<Field> field, shared_ptr<Game> game) {
    frameTime += game->delta;
    frameCurrent = int(frameTime / frameInterval) % frames;

    rTex.clear(sf::Color::Transparent);
    sprite.setTextureRect(frameCoord[frameCurrent]);
    rTex.draw(sprite);
    rTex.display();
}

Coin::Coin(shared_ptr<Game> game) : Entity(game) {
    frameTime = 0; frameInterval = 0.2; frameCurrent = 0; frames = 4;
    frameCoord = {
        {{0, 0}, {40, 40}},
        {{40, 0}, {40, 40}},
        {{80, 0}, {40, 40}},
        {{120, 0}, {40, 40}}
    };
    rTex = sf::RenderTexture({40, 40});
    rect = sf::FloatRect({0, 0}, {40, 40});
    sprite.setTexture(game->tex["coin"], true);
}
