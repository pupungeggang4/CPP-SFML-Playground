#include "general.hpp"
#include "decl.hpp"

Entity::Entity() {
    const sf::Texture& t = rTex.getTexture();
    spriteOut.setTexture(t, true);
}

void Entity::render(shared_ptr<Game> game) {
    shared_ptr<Field> field = game->field;

    frameTime += game->delta;
    frameCurrent = int(frameTime / frameInterval) % frames;

    rTex.clear(sf::Color::Transparent);
    sprite.setTextureRect(frameCoord[frameCurrent]);
    rTex.draw(sprite);
    rTex.display();

    Render::drawCenterCam(game->window, spriteOut, rect, field->cam);
}

void Entity::handleTick(shared_ptr<Game> game) {

}

Coin::Coin() : Entity() {
    frameTime = 0; frameInterval = 0.2; frameCurrent = 0; frames = 4;
    frameCoord = {
        {{0, 0}, {40, 40}},
        {{40, 0}, {40, 40}},
        {{80, 0}, {40, 40}},
        {{120, 0}, {40, 40}}
    };
    rTex = sf::RenderTexture({40, 40});
    rect = sf::FloatRect({0, 0}, {40, 40});

    sprite.setTexture(Res::tex["coin"]);
}

void Coin::render(shared_ptr<Game> game) {
    Entity::render(game);
}

void Coin::handleTick(shared_ptr<Game> game) {
    
}