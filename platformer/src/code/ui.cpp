#include "general.hpp"
#include "decl.hpp"

std::unordered_map<std::string, std::vector<int>> UI::title = {
    {"text_title", {24, 20}},
    {"button_start", {160, 160, 960, 80}},
    {"text_start", {184, 180}},
    {"button_lang", {160, 240, 960, 80}},
    {"text_lang", {184, 260}},
    {"button_erase", {160, 320, 960, 80}},
    {"text_erase", {184, 340}},
    {"button_exit", {160, 400, 960, 80}},
    {"text_exit", {184, 420}},
};

std::vector<std::vector<int>> UI::titleArrow = {
    {80, 160}, {80, 240}, {80, 320}, {80, 400}
};
