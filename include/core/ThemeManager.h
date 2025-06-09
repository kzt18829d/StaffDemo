#ifndef STAFFDEMO_THEMEMANAGER_H
#define STAFFDEMO_THEMEMANAGER_H
#include <memory>
#include <map>
#include <string>
#include "Theme.h"
#include <fstream>
#include "../utils/json.hpp"
#include "boost/signals2.hpp"


///@namespace Core
namespace Core {

    ///@brief Менеджер тем
    ///@details Используется для наложения цветового оформления элементам графического интерфейса
    ///@ingroup Core
    ///@ingroup Theme
    ///@see Theme
    class ThemeManager {
    public:
        using themeName = std::string;
    private:
        std::map<std::string, Theme> themeList;
        std::unique_ptr<Theme> currentTheme = nullptr;

    public:
        ThemeManager();
        ~ThemeManager();

        ThemeManager(const ThemeManager&) = delete;
        ThemeManager(ThemeManager&&) = delete;
        ThemeManager& operator=(const ThemeManager&) = delete;
        ThemeManager& operator=(ThemeManager&&) = delete;

        bool setTheme(const themeName& name);

        [[nodiscard]] Theme& getTheme() const;
        [[nodiscard]] std::vector<themeName> getThemeNamesList() const;
        [[nodiscard]] std::vector<Theme> getThemeList() const;
        void addTheme(Theme& theme);

        boost::signals2::signal<void(const Theme&)> ThemeChangedSignal;
    };

} // Core
// StaffDemo

#endif //STAFFDEMO_THEMEMANAGER_H
