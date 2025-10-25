#include "general.hpp"
#include "decl.hpp"

void SceneBattle::loop(shared_ptr<Game> game) {
    if (game->menu == false) {
        if (game->state == "") {
            game->field->handleTick(game);
        }
    }
    render(game);
}

void SceneBattle::render(shared_ptr<Game> game) {
    game->window.clear(sf::Color::White);
    Render::renderInit(game);

    game->field->render(game);
    Render::renderBattleUIUpper(game);

    if (game->state == "adventure_start") {
        Render::renderAdventureStart(game);
    }

    game->window.display();
}

void SceneBattle::keyDown(shared_ptr<Game> game, int key) {
    int alpha = key + 97;

    if (game->menu == false) {
        if (key == K_ESCAPE || alpha == 'q') {
            game->menu = true;
        }

        if (game->state == "adventure_start") {
            if (key == K_LEFT) {
                game->selectedAdventureStart = (game->selectedAdventureStart + 2) % 3;
            }
            if (key == K_RIGHT) {
                game->selectedAdventureStart = (game->selectedAdventureStart + 1) % 3;
            }
            if (key == K_RETURN) {
                game->state = "";
            }
        }
    } else {
        if (key == K_ESCAPE || alpha == 'q') {
            game->menu = false;
        }
    }
}

void SceneBattle::keyUp(shared_ptr<Game>game, int key) {

}
