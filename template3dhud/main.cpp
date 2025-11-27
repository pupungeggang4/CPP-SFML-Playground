#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>

#include <iostream>
#include <sstream>
#include <optional>

int main (int argc, char** argv) {
    sf::err().rdbuf(NULL);
    sf::RenderWindow window(sf::VideoMode({800, 800}), "Template 3D HUD");
    window.setFramerateLimit(60);
    sf::RenderTexture HUD({800, 800});
    sf::Vector2u windowSize = window.getSize();
    float angle = 0.f;

    std::stringstream ss;
    sf::Font font = sf::Font("font/neodgm.ttf");
    sf::Text text = sf::Text(font, "Angle: ", 32);
    text.setPosition({20, 20});
    text.setFillColor(sf::Color::White);

    bool running = true;
    while (running) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                running = false;
            }
        }

        HUD.setActive(true);
        HUD.clear(sf::Color::Transparent);
        ss.str("");
        ss << std::fixed << std::setprecision(1) << "Angle: " << angle;
        text.setString(ss.str());
        HUD.draw(text);
        HUD.display();

        window.setActive(true);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glViewport(0, 0, windowSize.x, windowSize.y);
        const sf::Texture& texture = HUD.getTexture();
        sf::Texture::bind(&texture);

        angle += 1.f;
        glRotatef(angle, 1.f, 0.5f, 1.f);

        glClearColor(0.f, 0.f, 0.f, 1.f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLineWidth(2);
        glDisable(GL_TEXTURE_2D);
        glBegin(GL_LINES);

        glColor3f(1.f, 1.f, 1.f);
        
        glVertex3f(-0.3f, -0.3f, -0.3f); glVertex3f(0.3f, -0.3f, -0.3f);
        glVertex3f(0.3f, -0.3f, -0.3f); glVertex3f(0.3f, -0.3f, 0.3f);
        glVertex3f(0.3f, -0.3f, 0.3f); glVertex3f(-0.3f, -0.3f, 0.3f);
        glVertex3f(-0.3f, -0.3f, 0.3f); glVertex3f(-0.3f, -0.3f, -0.3f);

        glVertex3f(-0.3f, 0.3f, -0.3f); glVertex3f(0.3f, 0.3f, -0.3f);
        glVertex3f(0.3f, 0.3f, -0.3f); glVertex3f(0.3f, 0.3f, 0.3f);
        glVertex3f(0.3f, 0.3f, 0.3f); glVertex3f(-0.3f, 0.3f, 0.3f);
        glVertex3f(-0.3f, 0.3f, 0.3f); glVertex3f(-0.3f, 0.3f, -0.3f);

        glVertex3f(-0.3f, -0.3f, -0.3f); glVertex3f(-0.3f, 0.3f, -0.3f);
        glVertex3f(0.3f, -0.3f, -0.3f); glVertex3f(0.3f, 0.3f, -0.3f);
        glVertex3f(0.3f, -0.3f, 0.3f); glVertex3f(0.3f, 0.3f, 0.3f);
        glVertex3f(-0.3f, -0.3f, 0.3f); glVertex3f(-0.3f, 0.3f, 0.3f);

        glEnd();

        window.setActive(true);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glViewport(0, 0, windowSize.x, windowSize.y);
        glEnable(GL_TEXTURE_2D);
        glBegin(GL_QUADS);
        glTexCoord2f(0.0, 1.0); glVertex2f(-1.0, -1.0);
        glTexCoord2f(1.0, 1.0); glVertex2f(1.0, -1.0);
        glTexCoord2f(1.0, 0.0); glVertex2f(1.0, 1.0);
        glTexCoord2f(0.0, 0.0); glVertex2f(-1.0, 1.0);
        glEnd();
        window.display();
        sf::Texture::bind(nullptr);
    }
    return 0;
}
