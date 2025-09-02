#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

int main()
{
    sf::err().rdbuf(NULL);
    unsigned int width = 0, height = 0;
    // create the window
    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();

    if (desktopMode.size.x > 2000) {
        width = 1600;
        height = 1200;
    } else {
        width = 800;
        height = 600;
    }
    sf::RenderWindow window(sf::VideoMode({width, height}), "OpenGL", sf::Style::Default, sf::State::Windowed);
    sf::View view({400, 300}, {800, 600});
    const sf::Font font("font/neodgm.ttf");
    sf::Text text(font, "Hello SFML", 32);

    window.setView(view);
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);

    // activate the window
    window.setActive(true);

    // run the main loop
    bool running = true;
    while (running)
    {
        // handle events
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                // end the program
                running = false;
            }
            else if (const auto* resized = event->getIf<sf::Event::Resized>())
            {
                // adjust the viewport when the window is resized
                glViewport(0, 0, resized->size.x, resized->size.y);
            }
        }
        window.setActive(true);
        // clear the buffers
        glClearColor(0.0, 0.0, 0.0, 1.0);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_COLOR_ARRAY);
        float vertice[9] = {0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0};
        float color[9] = {1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0};
        glVertexPointer(3, GL_FLOAT, sizeof(float) * 3, vertice);
        glColorPointer(3, GL_FLOAT, sizeof(float) * 3, color);
        // draw...
        glDrawArrays(GL_TRIANGLES, 0, 3);
        
        window.setActive(false);
        window.pushGLStates();
        window.draw(text);
        window.popGLStates();
        // end the current frame (internally swaps the front and back buffers)
        window.display();
    }

    // release resources...
}
