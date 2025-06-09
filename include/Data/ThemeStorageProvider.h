#ifndef STAFFDEMO_THEMESTORAGEPROVIDER_H
#define STAFFDEMO_THEMESTORAGEPROVIDER_H
#include "../core/Theme.h"
#include "../utils/json.hpp"
#include "fstream"
#include "ftxui/screen/color.hpp"
#include "cstring"
#include "../core/Usages.h"

///@defgroup Provider
///@defgroup Data

///@namespace Data
namespace Data {

    ///@brief Провайдер тем
    ///@details Используется для управления файлами тем
    ///@ingroup Provider
    ///@ingroup Data
    ///@see ThemeManager
    ///@see Theme
    class ThemeStorageProvider {
    private:
        Directory ThemeDirectory;
        std::vector<Core::Theme> loadedThemesList{};

        ColorID validateColor(ColorID colorId);
        Check validateThemeName(const std::string& themeName);

        ColorID getPaletteIndex(const ftxui::Color& color);

    public:
        explicit ThemeStorageProvider(Directory& themeDirectory);
        ~ThemeStorageProvider();
        void loadThemes(); ///< @brief Базовый загрузчик тем
        [[maybe_unused]] void loadThemes(Directory themeDirectory); ///< @brief Отладочный загрузчик тем.
        void saveThemes(std::vector<Core::Theme> themesTM);

        std::vector<Core::Theme> getLoadedThemeList() const;
    };
}



#endif //STAFFDEMO_THEMESTORAGEPROVIDER_H
