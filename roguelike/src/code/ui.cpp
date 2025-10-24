#include "general.hpp"
#include "decl.hpp"

std::unordered_map<std::string, std::vector<int>> UI::title = {
    {"text_title", {20, 20}},
    {"button_start", {160, 160, 960, 80}},
    {"text_start", {180, 180}},
    {"button_collection", {160, 240, 960, 80}},
    {"text_collection", {180, 260}},
    {"button_lang", {160, 320, 960, 80}},
    {"text_lang", {180, 340}},
    {"button_erase", {160, 400, 960, 80}},
    {"text_erase", {180, 420}},
    {"button_exit", {160, 480, 960, 80}},
    {"text_exit", {180, 500}},
};
std::vector<std::vector<int>> UI::titleArrow = {{80, 160}, {80, 240}, {80, 320}, {80, 400}, {80, 480}};
std::unordered_map<std::string, std::vector<int>> UI::menuVillage = {
    {"rect", {320, 200, 640, 320}},
    {"text_paused", {340, 220}},
    {"button_resume", {320, 280, 640, 80}},
    {"text_resume", {340, 300}},
    {"button_exit", {320, 360, 640, 80}},
    {"text_exit", {340, 380}},
    {"button_quit", {320, 440, 640, 80}},
    {"text_quit", {340, 460}}
};
std::vector<std::vector<int>> UI::menuVillageArrow = {{240, 280}, {240, 360}, {240, 440}};
std::unordered_map<std::string, std::vector<int>> UI::adventureConfirm = {
    {"rect", {320, 240, 640, 240}},
    {"text_title", {340, 260, 640, 240}},
    {"button_yes", {420, 380, 160, 80}},
    {"button_no", {740, 380, 160, 80}},
    {"text_yes", {440, 400}},
    {"text_no", {760, 400}}
};
std::vector<std::vector<int>> UI::adventureConfirmArrow = {{340, 380}, {660, 380}};
