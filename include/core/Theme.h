#ifndef STAFFDEMO_THEME_H
#define STAFFDEMO_THEME_H
#include "ftxui/screen/color.hpp"
#include "ftxui/dom/elements.hpp"
///@defgroup Theme Тема

using namespace ftxui;
///@brief Цветовая схема для тем
///@ingroup Theme
struct Theme {
    std::string name = "Default";
    ftxui::Color text_base          = Color::White;
    ftxui::Color text_primary       = Color::GrayLight;
    ftxui::Color text_secondary     = Color::GrayDark;
    ftxui::Color text_error         = Color::Red;
    ftxui::Color text_success       = Color::Green;
    ftxui::Color text_warning       = Color::Yellow;
    ftxui::Color text_info          = Color::Blue;
    ftxui::Color text_accent        = Color::Orange1;

    ftxui::Color bg_base            = Color::Black;
    ftxui::Color bg_primary         = Color::Default;
    ftxui::Color bg_secondary       = Color::GrayDark;
    ftxui::Color bg_selected        = Color::Blue;
    ftxui::Color bg_active          = Color::DarkBlue;

    ftxui::Color border_window      = Color::White;
    ftxui::Color border_primary     = Color::GrayLight;
    ftxui::Color border_focused     = Color::Blue;

    ftxui::Decorator button_style   = ftxui::nothing;
    ftxui::Decorator button_focused = ftxui::inverted;

    ftxui::Color text_window_header = Color::White;
    ftxui::Color border_window_header = Color::White;
};

#endif //STAFFDEMO_THEME_H
