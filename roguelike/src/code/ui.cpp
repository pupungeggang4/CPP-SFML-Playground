#pragma once
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
