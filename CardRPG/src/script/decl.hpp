#pragma once

class Game;
class Player;
class Field;
class Battle;

class Game {
    public:
        sf::RenderWindow window;
        std::unordered_map<std::string, sf::Texture> tex;
        sf::Texture emptyTex;
        sf::Sprite s = sf::Sprite(emptyTex);
        shared_ptr<Player> player;
        std::unordered_map<std::string, bool> keyPressed = {
            {"up", false}, {"left", false}, {"down", false}, {"right", false}
        };

        Game();
        void run(shared_ptr<Game> game);
        void loop(shared_ptr<Game> game);
};

class Player {
    public:
        sf::FloatRect rect;
        float speed = 200.0f;

        Player();
        void move(shared_ptr<Game> game);
};

bool pointInsideRectUI(sf::Vector2f pos, sf::FloatRect rect);

void loopTitle(shared_ptr<Game> game);
void renderTitle(shared_ptr<Game> game);