#pragma once
#include "general.hpp"
#include "decl.hpp"

std::unordered_map<std::string, std::any> UI::title = {
    {"text_title", {24, 24}},
    {"button_start", {160, 160, 960, 80}},
    {"text_start", {184, 184}},
    {"button_collection", {160, 240, 960, 80}},
    {"text_collection", {184, 264}},
    {"button_exit", {160, 320, 960, 80}},
    {"text_exit", {184, 344}},
    {"arrow", {{80, 160}, {80, 240}, {80, 320}}}
};