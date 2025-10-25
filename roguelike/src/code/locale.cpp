#include "general.hpp"
#include "decl.hpp"

std::unordered_map<std::string, std::unordered_map<std::string, sf::String>> Locale::data = {
    {"ko", {
        {"game_name", L"로그라이크"},
        {"start_game", L"게임 시작"},
        {"lang", L"한국어"},
        {"collection", L"수집품"},
        {"erase_data", L"데이터 삭제"},
        {"exit", L"끝내기"},
        {"paused", L"일시정지"},
        {"resume", L"계속하기"},
        {"to_title", L"타이틀 화면으로 돌아가기"},
        {"adventure_start", L"모험을 시작하겠습니까?"},
        {"yes", L"네"},
        {"no", L"아니요"},
        {"select_weapon", L"무기를 선택하세요."},
    }},
    {"en", {
        {"game_name", "Roguelike"},
        {"start_game", "Start Game"},
        {"lang", "English"},
        {"collection", "Collection"},
        {"erase_data", "Erase Data"},
        {"exit", "Exit"},
        {"paused", "Paused"},
        {"resume", "Resume"},
        {"to_title", "Exit to title"},
        {"adventure_start", "Start Adventure?"},
        {"yes", "yes"},
        {"no", "no"},
        {"select_weapon", "Select Weapon."}
    }}
};
