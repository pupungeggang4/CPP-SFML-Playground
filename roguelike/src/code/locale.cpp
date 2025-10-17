#include "general.hpp"
#include "decl.hpp"

std::unordered_map<std::string, std::unordered_map<std::string, sf::String>> Locale::data = {
    {"ko",
        {{"game_name", L"로그라이크"},
        {"start_game", L"게임 시작"},
        {"lang", L"한국어"},
        {"collection", L"수집품"},
        {"erase_data", L"데이터 삭제"},
        {"exit", L"끝내기"}
        },
    },
    {"en",
        {{"game_name", "Roguelike"},
        {"start_game", "Start Game"},
        {"lang", "English"},
        {"collection", "Collection"},
        {"erase_data", "Erase Data"},
        {"exit", "Exit"}
        }
    }
};
