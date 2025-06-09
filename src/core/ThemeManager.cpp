#include "core/ThemeManager.h"

namespace Core {

    ThemeManager::ThemeManager() {
        themeList["Default"] = Theme();
        setTheme("Default");
    }

    bool ThemeManager::setTheme(const std::string& name) {
        if (auto it = themeList.find(name); it != themeList.end()) {
            this->currentTheme = std::make_unique<Theme>(it->second);
            this->ThemeChangedSignal(*currentTheme);
            return true;
        }
        return false;
    }

    Theme &ThemeManager::getTheme() const {
        return *this->currentTheme;
    }

    std::vector<ThemeManager::themeName> ThemeManager::getThemeNamesList() const {
        std::vector<std::string> themeNames;
        std::for_each(this->themeList.begin(), this->themeList.end(), [&](const auto& theme) {
            themeNames.push_back(theme.first);
        });
        return themeNames;
    }

    void ThemeManager::addTheme(Theme &theme) {
        if (this->themeList.contains(theme.name)) {
            // добавить сигнал об ошибке смены темы (уже имеется)
            return;
        }
        this->themeList[theme.name] = std::move(theme);
    }

    ThemeManager::~ThemeManager() = default;

    std::vector<Theme> ThemeManager::getThemeList() const {
        std::vector<Theme> themeListVector;
        std::for_each(this->themeList.begin(), this->themeList.end(), [&](const auto& current){
            themeListVector.push_back(current.second);
        });
        return themeListVector;
    }

} // Core
