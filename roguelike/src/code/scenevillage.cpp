#include "scenetitle.hpp"
#include "scenebattle.hpp"
#include "scenevillage.hpp"

#include "village.hpp"
#include "render.hpp"
#include "field.hpp"

#include "game.hpp"

SceneVillage::SceneVillage(shared_ptr<Game> game) {

}

void SceneVillage::loop(shared_ptr<Game> game) {
    if (game->menu == false) {
        if (game->state == "") {
            game->village->handleTick(game);
        }
    }
    render(game);
}

void SceneVillage::render(shared_ptr<Game> game) {
    game->window.clear(sf::Color::White);
    Render::renderInit(game);

    game->village->render(game);

    if (game->state == "adventure_confirm") {
        Render::renderAdventureConfirm(game);
    }

    if (game->menu == true) {
        Render::renderMenuVillage(game);
    }
    game->window.display();
}

void SceneVillage::keyDown(shared_ptr<Game> game, int key) {
    int alpha = key + 97;

    if (game->menu == false) {
        if (key == K_ESCAPE || alpha == 'q') {
            game->menu = true;
            game->selectedMenuVillage = 0;
        }
        if (game->state == "") {
            if (alpha == 'x') {
                game->village->player->interact(game);
            }
        } else if (game->state == "adventure_confirm") {
            if (key == K_LEFT) {
                game->selectedAdventureConfirm = (game->selectedAdventureConfirm + 1) % 2;
            }
            if (key == K_RIGHT) {
                game->selectedAdventureConfirm = (game->selectedAdventureConfirm + 1) % 2;
            }
            if (key == K_RETURN) {
                if (game->selectedAdventureConfirm == 0) {
                    game->scene = make_shared<SceneBattle>(game);
                    game->state = "adventure_start";
                    game->selectedAdventureStart = 0;
                    game->field = make_shared<Field>(game);
                } else if (game->selectedAdventureConfirm == 1) {
                    game->state = "";
                }
            }
        }
    } else {
        if (key == K_ESCAPE || alpha == 'q') {
            game->menu = false;
        }
        if (key == K_UP) {
            game->selectedMenuVillage = (game->selectedMenuVillage + 2) % 3;
        }
        if (key == K_DOWN) {
            game->selectedMenuVillage = (game->selectedMenuVillage + 1) % 3;
        }
        if (key == K_RETURN) {
            if (game->selectedMenuVillage == 0) {
                game->menu = false;
            } else if (game->selectedMenuVillage == 1) {
                game->menu = false;
                game->scene = make_shared<SceneTitle>(game);
            } else if (game->selectedMenuVillage == 2) {
                game->window.close();
            }
        }
    }
}

void SceneVillage::keyUp(shared_ptr<Game> game, int key) {

}
