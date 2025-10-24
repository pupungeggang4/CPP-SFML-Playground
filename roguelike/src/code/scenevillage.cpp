#pragma once
#include "general.hpp"
#include "decl.hpp"

void SceneVillage::loop(shared_ptr<Game> game) {
    render(game);
}

void SceneVillage::render(shared_ptr<Game> game) {
    game->window.clear(sf::Color::White);
    Render::renderInit(game);

    if (game->menu == true) {
        Render::renderMenu(game);
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
                game->scene = "title";
            } else if (game->selectedMenuVillage == 2) {
                game->window.close();
            }
        }
    }
}

void SceneVillage::keyUp(shared_ptr<Game> game, int key) {

}
