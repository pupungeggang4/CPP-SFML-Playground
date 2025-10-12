#pragma once

#include <iostream>

#include <cmath>
#include <string>
#include <any>
#include <variant>
#include <vector>
#include <array>
#include <unordered_map>

#include <memory>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using std::shared_ptr;
using std::make_shared;
using UICoord = std::variant<std::vector<int>, std::vector<std::vector<int>> >;