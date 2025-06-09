#ifndef STAFFDEMO_THEME_H
#define STAFFDEMO_THEME_H
#include "ftxui/screen/color.hpp"
#include "ftxui/dom/elements.hpp"
#include "ftxui/screen/color_info.hpp"

///@defgroup Theme Тема

using namespace ftxui;
#define TEXT_BASE "text_base"
#define TEXT_PRIMARY "text_primary"
#define TEXT_SECONDARY "text_secondary"
#define TEXT_ERROR "text_error"
#define TEXT_SUCCESS "text_success"
#define TEXT_WARNING "text_warning"
#define TEXT_INFO "text_info"
#define TEXT_ACCENT "text_accent"
#define BG_BASE "bg_base"
#define BG_PRIMARY "bg_primary"
#define BG_SECONDARY "bg_secondary"
#define BG_SELECTED "bg_selected"
#define BG_ACTIVE "bg_active"
#define BORDER_WINDOW "border_window"
#define BORDER_PRIMARY "border_primary"
#define BORDER_FOCUSED "border_focused"
#define BUTTON_STYLE "button_style"
#define BUTTON_FOCUSED "button_focused"
#define TEXT_WINDOW_HEADER "text_window_header"
#define BORDER_WINDOW_HEADER "border_window_header"

///@namespace Core
namespace Core {
    ///@brief Цветовая схема для тем
    ///@ingroup Core
    ///@ingroup Theme
    struct Theme {
        std::string name = "Default";
        ftxui::Color text_base = Color::White;             // 15
        ftxui::Color text_primary = Color::GrayLight;         // 7
        ftxui::Color text_secondary = Color::GrayDark;          // 8
        ftxui::Color text_error = Color::RedLight;          // 9
        ftxui::Color text_success = Color::GreenLight;        // 10
        ftxui::Color text_warning = Color::YellowLight;       // 11
        ftxui::Color text_info = Color::BlueLight;         // 12
        ftxui::Color text_accent = Color::Orange1;           // 214

        ftxui::Color bg_base = Color::Black;             // 0
        ftxui::Color bg_primary = Color::Default;           // -1
        ftxui::Color bg_secondary = Color::GrayDark;          // 8
        ftxui::Color bg_selected = Color::Blue;              // 4
        ftxui::Color bg_active = Color::DarkBlue;          // 18

        ftxui::Color border_window = Color::White;             // 15
        ftxui::Color border_primary = Color::GrayLight;         // 7
        ftxui::Color border_focused = Color::Blue;              // 4

        ftxui::Decorator button_style = ftxui::nothing;           // -8
        ftxui::Decorator button_focused = ftxui::inverted;          // -9

        ftxui::Color text_window_header = Color::White;             // 15
        ftxui::Color border_window_header = Color::White;           // 15

        bool operator==(const Theme& other) const { return this->name == other.name;}
        bool operator!=(const Theme& other) const { return !operator==(other); }
        bool empty() const { return this->name.empty(); }
    };
}

#endif //STAFFDEMO_THEME_H
