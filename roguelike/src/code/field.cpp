#include "field.hpp"
#include "res.hpp"
#include "game.hpp"
#include "render.hpp"

Field::Field(shared_ptr<Game> game) {
    player = make_shared<FieldPlayer>(game);
    for (int i = 0; i < 10; i++) {
        shared_ptr<Drop> d = make_shared<Drop>(game, "exporb", 10);
        drop.push_back(d);
    }
}

void Field::handleTick(shared_ptr<Game> game) {
    player->handleTick(game);
    for (int i = drop.size() - 1; i >= 0; i--) {
        dropCurrent = drop[i];
        drop[i]->handleTick(game);
    }
    camera.position.x = player->rect.position.x;
    camera.position.y = player->rect.position.y;
}

void Field::render(shared_ptr<Game> game) {
    player->render(game);
    for (int i = drop.size() - 1; i >= 0; i--) {
        drop[i]->render(game);
    }
}

Entity::Entity(shared_ptr<Game> game) {

}

void Entity::handleTick(shared_ptr<Game> game) {

}

void Entity::render(shared_ptr<Game> game) {

}

Unit::Unit(shared_ptr<Game> game) : Entity(game) {

}

Drop::Drop(shared_ptr<Game> game, std::string type, int amount) : Entity(game) {
    rect.position.x = 200 + std::rand() % 200;
    rect.position.y = -100 + std::rand() % 200;
    this->type = type;
    this->amount = amount;

    if (this->type == "coin") {
        sprite.setTexture(Res::img->at("coin"), true);
    } else if (this->type == "exporb") {
        sprite.setTexture(Res::img->at("exporb"), true);
    }
    const sf::Texture& tmpTex = rt.getTexture();
    spriteOut.setTexture(tmpTex, true);
}

void Drop::handleTick(shared_ptr<Game> game) {
    shared_ptr<FieldPlayer> player = game->field->player;
    if ((rect.position - player->rect.position).length() < 60) {
        if (type == "coin") {
            player->gold += amount;
        } else if (type == "exporb") {
            player->exp += amount;
            if (player->exp >= player->expMax) {
                player->level += 1;
                player->exp -= player->expMax;
                player->expMax = (player->level + 1) * 10;
            }
        }

        game->field->drop.erase(std::find(game->field->drop.begin(), game->field->drop.end(), game->field->dropCurrent));
    }
}

void Drop::render(shared_ptr<Game> game) {
    rt.clear(sf::Color::Transparent);
    rt.draw(sprite);
    rt.display();

    Render::drawCenterCam(game->window, spriteOut, rect, game->field->camera);
}

FieldPlayer::FieldPlayer(shared_ptr<Game> game) : Unit(game) {
    rect.size.x = 80;
    rect.size.y = 80;

    sprite.setTexture(Res::img->at("player"), true);
    const sf::Texture& tmpTex = rt.getTexture();
    spriteOut.setTexture(tmpTex, true);
}

void FieldPlayer::handleTick(shared_ptr<Game> game) {
    move(game);
}

void FieldPlayer::move(shared_ptr<Game> game) {
    sf::Vector2f velocity = {0, 0};
    sf::Vector2f tempPosition = {rect.position.x, rect.position.y};
    bool xPressed = false;
    bool yPressed = false;

    if (game->keyPressed["left"] == true) {
        xPressed = true;
        velocity.x -= 1;
    }
    if (game->keyPressed["right"] == true) {
        xPressed = true;
        velocity.x += 1;
    }
    if (game->keyPressed["up"] == true) {
        yPressed = true;
        velocity.y -= 1;
    }
    if (game->keyPressed["down"] == true) {
        yPressed = true;
        velocity.y += 1;
    }

    if (xPressed && yPressed) {
        velocity *= 0.7f;
    }

    tempPosition.x += velocity.x * speed * game->delta;
    tempPosition.y += velocity.y * speed * game->delta;

    rect.position.x = tempPosition.x;
    rect.position.y = tempPosition.y;
}

void FieldPlayer::render(shared_ptr<Game> game) {
    rt.clear(sf::Color::Transparent);
    rt.draw(sprite);
    rt.display();

    Render::drawCenterCam(game->window, spriteOut, rect, game->field->camera);
}
