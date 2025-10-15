#include "general.hpp"
#include "decl.hpp"

LocaleForm Locale::data = {
    {"ko", {
        {"game_name", L"플랫포머"},
        {"start_game", L"게임 시작"},
        {"lang", L"한국어"},
        {"erase_data", L"데이터 삭제"},
        {"exit", L"종료"},
        {"paused", L"일시정지됨"},
        {"resume", L"계속하기"},
        {"to_title", L"타이틀 화면으로 돌아가기"},
    }},
    {"en", {
        {"game_name", "Platformer"},
        {"start_game", "Start Game"},
        {"lang", "English"},
        {"erase_data", "Erase Data"},
        {"exit", "Exit"},
        {"paused", "Paused"},
        {"resume", "Resume"},
        {"to_title", "Exit to title"},
    }},
};