//
// Created by hid3h on 26.05.2025.
//

#include "core/ThemeManager.h"


namespace StaffDemo::Core {

    ThemeManager::ThemeManager() {
        themeList["Default"] = Theme();
        setTheme("Default");
    }

    ThemeManager &ThemeManager::instance() {
        if (inst == nullptr) inst = new ThemeManager();
        return *inst;
    }

    bool ThemeManager::setTheme(const std::string& name) {
        if (auto it = themeList.find(name); it != themeList.end()) {
            currentTheme = std::make_unique<Theme>(it->second);
            ThemeChangedSignal(*currentTheme);
            return true;
        }
        return false;
    }

    Theme &ThemeManager::getTheme() const {
        return *currentTheme;
    }

    std::vector<ThemeManager::themeName> ThemeManager::getThemeNamesList() const {
        std::vector<std::string> themeNames;
        std::for_each(themeList.begin(), themeList.end(), [&](const auto& theme) {
            themeNames.push_back(theme.first);
        });
        return themeNames;
    }

    void ThemeManager::addTheme(Theme &theme) {
        if (themeList.contains(theme.name)) {
            // добавить сигнал об ошибке смены темы (уже имеется)
            return;
        }
        themeList[theme.name] = std::move(theme);
    }

    void ThemeManager::loadFromJson(std::string &themeFileDirectory) {
        std::vector<nlohmann::json> loadedThemes;
        std::ifstream themeJson (std::move(themeFileDirectory), std::ios::in);
        if (!themeJson.is_open()) {
            // log
            throw std::ios::failure("Open file error");
        }
        nlohmann::json themeJsonTemp;
        std::for_each(themeJsonTemp.begin(), themeJsonTemp.end(), [&](nlohmann::json _json){
            Theme newTheme;
            newTheme.name = _json;
            for (const auto& row : _json.items()) {
                if (row.key() == TEXT_BASE)                 newTheme.text_base               = Color::Palette256(row.value());
                else if (row.key() == TEXT_PRIMARY)         newTheme.text_primary            = Color::Palette256(row.value());
                else if (row.key() == TEXT_SECONDARY)       newTheme.text_secondary          = Color::Palette256(row.value());
                else if (row.key() == TEXT_ERROR)           newTheme.text_error              = Color::Palette256(row.value());
                else if (row.key() == TEXT_SUCCESS)         newTheme.text_success            = Color::Palette256(row.value());
                else if (row.key() == TEXT_WARNING)         newTheme.text_warning            = Color::Palette256(row.value());
                else if (row.key() == TEXT_INFO)            newTheme.text_info               = Color::Palette256(row.value());
                else if (row.key() == TEXT_ACCENT)          newTheme.text_accent             = Color::Palette256(row.value());
                else if (row.key() == BG_BASE)              newTheme.bg_base                 = Color::Palette256(row.value());
                else if (row.key() == BG_PRIMARY)           newTheme.bg_primary              = Color::Palette256(row.value());
                else if (row.key() == BG_SECONDARY)         newTheme.bg_secondary            = Color::Palette256(row.value());
                else if (row.key() == BG_SELECTED)          newTheme.bg_selected             = Color::Palette256(row.value());
                else if (row.key() == BG_ACTIVE)            newTheme.bg_active               = Color::Palette256(row.value());
                else if (row.key() == BORDER_WINDOW)        newTheme.border_window           = Color::Palette256(row.value());
                else if (row.key() == BORDER_PRIMARY)       newTheme.border_primary          = Color::Palette256(row.value());
                else if (row.key() == BORDER_FOCUSED)       newTheme.border_focused          = Color::Palette256(row.value());
                else if (row.key() == BUTTON_STYLE)         newTheme.button_style            = ftxui::nothing;
                else if (row.key() == BUTTON_FOCUSED)       newTheme.button_focused          = ftxui::inverted;
                else if (row.key() == TEXT_WINDOW_HEADER)   newTheme.text_window_header      = Color::Palette256(row.value());
                else if (row.key() == BORDER_WINDOW_HEADER) newTheme.border_window_header    = Color::Palette256(row.value());
            }
            this->addTheme(newTheme);
        });
        // log
    }

    template<typename T>
    std::any ThemeManager::getColorByID(T toTranslate) {
        if (!std::is_same_v<T, int>) {
            // log неверное значение при чтении json
            throw std::runtime_error("Неверное чтение из файла.");
        }
        switch (toTranslate) {
            case -1:
                return Color::Default;
            case -8:
                return ftxui::nothing;
            case -9:
                return ftxui::inverted;
            default:
                if (toTranslate < 0 or toTranslate > 256) { // ftxui::Color Palette 256
                    // log error
                    throw std::runtime_error("Неверное чтение из файла.");
                }
                return toTranslate;
        }
    }
} // Core
// StaffDemo