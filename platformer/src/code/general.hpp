#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <variant>
#include <array>
#include <vector>
#include <unordered_map>
#include <memory>
#include <cmath>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using std::shared_ptr;
using std::make_shared;

#define K_LEFT 87
#define K_RIGHT 86
#define K_DOWN 88
#define K_UP 89
#define K_RETURN 36
#define K_SPACE 40
#define K_ESCAPE 37

using UICoord = std::variant<std::vector<int>, std::vector<std::vector<int>>>;
using LocaleForm = std::unordered_map<std::string, std::unordered_map<std::string, sf::String>>;