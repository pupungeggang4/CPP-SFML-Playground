#include "general.hpp"
#include "decl.hpp"

std::unordered_map<std::string, std::vector<int>> UI::title = {
    {"text_title", {24, 20}},
    {"button_start", {160, 160, 960, 80}},
    {"text_start", {180, 180}},
    {"button_lang", {160, 240, 960, 80}},
    {"text_lang", {180, 260}},
    {"button_erase", {160, 320, 960, 80}},
    {"text_erase", {180, 340}},
    {"button_exit", {160, 400, 960, 80}},
    {"text_exit", {180, 420}},
};
std::vector<std::vector<int>> UI::titleArrow = {{80, 160}, {80, 240}, {80, 320}, {80, 400}};
std::unordered_map<std::string, std::vector<int>> UI::menu = {
    {"rect", {320, 200, 640, 320}},
    {"text_paused", {340, 220}},
    {"button_resume", {320, 280, 640, 80}},
    {"text_resume", {340, 300}},
    {"button_to_title", {320, 360, 640, 80}},
    {"text_to_title", {340, 380}},
    {"button_exit", {320, 440, 640, 80}},
    {"text_exit", {340, 460}},
};
std::vector<std::vector<int>> UI::menuArrow = {{240, 280}, {240, 360}, {240, 440}};
std::unordered_map<std::string, std::vector<int>> UI::field = {
    {"icon_coin", {20, 20}},
    {"text_coin", {64, 20}}
};
