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

    if (game->menu == true) {
        Render::renderMenuBattle(game);
    }

    game->window.display();
}

void SceneBattle::keyDown(shared_ptr<Game> game, int key) {
    int alpha = key + 97;

    if (game->menu == false) {
        if (key == K_ESCAPE || alpha == 'q') {
            game->menu = true;
            game->selectedMenuBattle = 0;
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
        if (key == K_UP) {
            game->selectedMenuBattle = (game->selectedMenuBattle + 3) % 4;
        }
        if (key == K_DOWN) {
            game->selectedMenuBattle = (game->selectedMenuBattle + 1) % 4;
        }
        if (key == K_RETURN) {
            if (game->selectedMenuBattle == 0) {
                game->menu = false;
                game->state = "";
            } else if (game->selectedMenuBattle == 1) {
                game->menu = false;
                game->scene = "village";
                game->state = "";
            } else if (game->selectedMenuBattle == 2) {
                game->menu = false;
                game->scene = "title";
                game->state = "";
            } else if (game->selectedMenuBattle == 3) {
                game->window.close();
            }
        }
    }
}

void SceneBattle::keyUp(shared_ptr<Game>game, int key) {

}
