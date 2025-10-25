#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

#include <string>
#include <variant>

#include <vector>
#include <iterator>
#include <algorithm>
#include <array>
#include <unordered_map>

#include <memory>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

using std::shared_ptr;
using std::make_shared;
typedef std::vector<int> UI1D;
typedef std::vector<std::vector<int>> UI2D;
using UICoord = std::variant<std::vector<int>, std::vector<std::vector<int>>>;

#define K_RIGHT 86
#define K_LEFT 87
#define K_DOWN 88
#define K_UP 89
#define K_RETURN 36
#define K_ESCAPE 37
#define K_SPACE 40
