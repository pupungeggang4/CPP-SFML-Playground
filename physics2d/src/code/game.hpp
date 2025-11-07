#include "general.hpp"
#include "fdef.hpp"

class Game {
    public:
        sf::RenderWindow window;
        std::string scene = "main";
        unsigned int width, height;
        Game();
        void run();
        void loop();
};
