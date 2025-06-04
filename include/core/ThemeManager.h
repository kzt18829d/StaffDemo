#ifndef STAFFDEMO_THEMEMANAGER_H
#define STAFFDEMO_THEMEMANAGER_H
#include <memory>
#include <map>
#include <string>
#include "Theme.h"
#include "Signal2.h"
#include <fstream>
#include "../utils/json.hpp"


namespace StaffDemo::Core {

    class ThemeManager {
    public:
        using themeName = std::string;
    private:
        ThemeManager();
        ~ThemeManager() {
            delete inst;
        }

        template<typename T>
        [[maybe_unused]]std::any getColorByID(T toTranslate);
        std::map<std::string, Theme> themeList;
        std::unique_ptr<Theme> currentTheme = nullptr;
        static ThemeManager* inst;

    public:
        ThemeManager(const ThemeManager&) = delete;
        ThemeManager(ThemeManager&&) = delete;
        ThemeManager& operator=(const ThemeManager&) = delete;
        ThemeManager& operator=(ThemeManager&&) = delete;

        static ThemeManager& instance();
        bool setTheme(const themeName& name);

        void loadFromJson(std::string& themeFileDirectory);

        Theme& getTheme() const;
        std::vector<themeName> getThemeNamesList() const;
        void addTheme(Theme& theme);


        Signal<const Theme&> ThemeChangedSignal;
    };

} // Core
// StaffDemo

#endif //STAFFDEMO_THEMEMANAGER_H
