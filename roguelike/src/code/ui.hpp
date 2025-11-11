#pragma once
#include "general.hpp"

class UI {
    public:
        static std::unordered_map<std::string, std::vector<int>> title;
        static std::vector<std::vector<int>> titleArrow;
        static std::unordered_map<std::string, std::vector<int>> village;
        static std::unordered_map<std::string, std::vector<int>> menuVillage;
        static std::vector<std::vector<int>> menuVillageArrow;
        static std::unordered_map<std::string, std::vector<int>> adventureConfirm;
        static std::vector<std::vector<int>> adventureConfirmArrow;

        static std::unordered_map<std::string, UICoord> window;
        static std::vector<std::vector<int>> adventureStartArrow;
        static std::unordered_map<std::string, std::vector<int>> battle;
        static std::unordered_map<std::string, std::vector<int>> menuBattle;
        static std::vector<std::vector<int>> menuBattleArrow;
};