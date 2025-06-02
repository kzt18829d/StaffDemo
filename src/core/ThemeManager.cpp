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
} // Core
// StaffDemo