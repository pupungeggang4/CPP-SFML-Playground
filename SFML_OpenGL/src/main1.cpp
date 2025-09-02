#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <glad/gl.h>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main()
{
    // create the window
    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
    std::cout << desktopMode.size.x << std::endl;
    unsigned int width, height;
    if (desktopMode.size.x > 2000) {
        width = 1600;
        height = 1200;
    } else {
        width = 800;
        height = 600;
    }
    sf::ContextSettings settings;
    settings.depthBits = 24;
    settings.stencilBits = 8;
    settings.antiAliasingLevel = 0;
    settings.majorVersion = 3;
    settings.minorVersion = 3;
    settings.attributeFlags = sf::ContextSettings::Attribute::Default;
    sf::RenderWindow window(sf::VideoMode({width, height}), "OpenGL", sf::Style::Default, sf::State::Windowed, settings);
    window.setVerticalSyncEnabled(true);
    sf::View view({400.f, 300.f}, {800.f, 600.f});

    window.setView(view);
    const sf::Font font("font/neodgm.ttf");
    sf::Text text(font, "Hello SFML", 32);
    text.setPosition({20, 20});

    sf::err().rdbuf(NULL);
    // activate the window
    window.setActive(true);

    // load resources, initialize the OpenGL states, ...
    gladLoadGL(sf::Context::getFunction);
    std::ifstream f;
    f.open("./shader/vertex.vert");
    std::stringstream vSourceSS;
    vSourceSS << f.rdbuf();
    std::string vSourceStr = vSourceSS.str();
    vSourceStr.append(1, 0);
    const GLchar *vSource = vSourceStr.c_str();
    f.close();

    f.open("./shader/fragment.frag");
    std::stringstream fSourceSS;
    fSourceSS << f.rdbuf();
    std::string fSourceStr = fSourceSS.str();
    fSourceStr.append(1, 0);
    const GLchar *fSource = fSourceStr.c_str();
    f.close();

    std::vector<float> bTriangleData = {
        -1.0, -1.0, 0.0, 1.0, -1.0, 0.0, 1.0, 1.0, 0.0    
    };
    std::vector<float> bHUDData = {
        1.0, -1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0,
        -1.0, -1.0, 0.0, 1.0, -1.0, -1.0, 0.0, 1.0,
        1.0, 1.0, 1.0, 0.0, -1.0, 1.0, 0.0, 0.0
    };

    GLuint program, vShader, fShader;
    GLuint vao, bTriangle, bHUD, texture;
    GLint laPosition, laTexcoord, luColor, luModeV, luModeF;

    vShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vShader, 1, &vSource, NULL);
    glCompileShader(vShader);
    fShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fShader, 1, &fSource, NULL);
    glCompileShader(fShader);
    program = glCreateProgram();
    glAttachShader(program, vShader);
    glAttachShader(program, fShader);
    glLinkProgram(program);

    int success; char infoLog[2048];
    glGetShaderiv(vShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vShader, 2048, NULL, infoLog);
        std::cout << "v " << infoLog << std::endl;
    }
    glGetShaderiv(fShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fShader, 2048, NULL, infoLog);
        std::cout << "f " << infoLog << std::endl;
    }

    luColor = glGetUniformLocation(program, "u_color");
    luModeV = glGetUniformLocation(program, "u_mode_v");
    luModeF = glGetUniformLocation(program, "u_mode_f");
    laPosition = glGetAttribLocation(program, "a_position");
    laTexcoord = glGetAttribLocation(program, "a_texcoord");

    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &bTriangle);
    glGenBuffers(1, &bHUD);
    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, bTriangle);
    glBufferData(GL_ARRAY_BUFFER, bTriangleData.size() * sizeof(float), &bTriangleData[0], GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, bHUD);
    glBufferData(GL_ARRAY_BUFFER, bHUDData.size() * sizeof(float), &bHUDData[0], GL_STATIC_DRAW);

    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

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

        window.clear();
        window.setActive(true);
        // clear the buffers
        glClearColor(0.0, 0.0, 1.0, 1.0);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glUseProgram(program);

        // draw...
        glBindVertexArray(vao);

        glUniform1i(luModeV, 0);
        glUniform1i(luModeF, 0);
        glUniform4f(luColor, 1.0, 0.0, 1.0, 1.0);

        glBindBuffer(GL_ARRAY_BUFFER, bTriangle);
        glVertexAttribPointer(laPosition, 3, GL_FLOAT, false, sizeof(float) * 3, (void*)(0));
        glEnableVertexAttribArray(laPosition);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glBindVertexArray(0);

        window.setActive(false);
        window.pushGLStates();
        window.draw(text);
        window.popGLStates();
        window.display();
    }

    // release resources...
}
