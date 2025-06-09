//
// Created by hid3h on 08.06.2025.
//

#include "ThemeStorageProvider.h"
namespace Data {

    ThemeStorageProvider::ThemeStorageProvider(Directory& themeDirectory) : ThemeDirectory(themeDirectory), loadedThemesList({}) {
        // log
    }

    ThemeStorageProvider::~ThemeStorageProvider() = default;

    void ThemeStorageProvider::loadThemes() {

        std::ifstream ThemeFile(ThemeDirectory, std::ios::in);
        if (!ThemeFile.is_open()) throw std::ios::failure("Open ThemeFile error");
        nlohmann::json themeTemp;

        try {
            ThemeFile >> themeTemp;
        } catch (const nlohmann::json::parse_error& parse_error){
            ThemeFile.close();
            throw std::runtime_error("parse error");
        }
        ThemeFile.close();

        for (const auto& [themeName, themeJson]: themeTemp.items()) {
            if (!validateThemeName(themeName)) continue;

            Core::Theme newTheme;
            newTheme.name = themeName;

            using namespace ftxui;
            Check validateError = false;
            for (const auto& row : themeJson.items()) {
                if (!row.value().is_number_integer()) { validateError = true; break; }

                ColorID colorId = row.value().get<short>();

                if (row.key() == TEXT_BASE)                 newTheme.text_base              = Color::Palette256(validateColor(colorId));
                else if (row.key() == TEXT_PRIMARY)         newTheme.text_primary           = Color::Palette256(validateColor(colorId));
                else if (row.key() == TEXT_SECONDARY)       newTheme.text_secondary         = Color::Palette256(validateColor(colorId));
                else if (row.key() == TEXT_ERROR)           newTheme.text_error             = Color::Palette256(validateColor(colorId));
                else if (row.key() == TEXT_SUCCESS)         newTheme.text_success           = Color::Palette256(validateColor(colorId));
                else if (row.key() == TEXT_WARNING)         newTheme.text_warning           = Color::Palette256(validateColor(colorId));
                else if (row.key() == TEXT_INFO)            newTheme.text_info              = Color::Palette256(validateColor(colorId));
                else if (row.key() == TEXT_ACCENT)          newTheme.text_accent            = Color::Palette256(validateColor(colorId));
                else if (row.key() == BG_BASE)              newTheme.bg_base                = Color::Palette256(validateColor(colorId));
                else if (row.key() == BG_PRIMARY)           newTheme.bg_primary             = Color::Palette256(validateColor(colorId));
                else if (row.key() == BG_SECONDARY)         newTheme.bg_secondary           = Color::Palette256(validateColor(colorId));
                else if (row.key() == BG_SELECTED)          newTheme.bg_selected            = Color::Palette256(validateColor(colorId));
                else if (row.key() == BG_ACTIVE)            newTheme.bg_active              = Color::Palette256(validateColor(colorId));
                else if (row.key() == BORDER_WINDOW)        newTheme.border_window          = Color::Palette256(validateColor(colorId));
                else if (row.key() == BORDER_PRIMARY)       newTheme.border_primary         = Color::Palette256(validateColor(colorId));
                else if (row.key() == BORDER_FOCUSED)       newTheme.border_focused         = Color::Palette256(validateColor(colorId));
                else if (row.key() == BUTTON_STYLE)         newTheme.button_style           = ftxui::nothing;
                else if (row.key() == BUTTON_FOCUSED)       newTheme.button_focused         = ftxui::inverted;
                else if (row.key() == TEXT_WINDOW_HEADER)   newTheme.text_window_header     = Color::Palette256(validateColor(colorId));
                else if (row.key() == BORDER_WINDOW_HEADER) newTheme.border_window_header   = Color::Palette256(validateColor(colorId));
                else {
                    // log не загрузилась тема
//                    throw std::invalid_argument("Invalid argument in json (" + appSettings->getThemeDirectory() + "): [" + row.key() + "]");
                    return;
                }
            }
            if (validateError) {
                // log тема не загружена
                break;
            }

            if (auto iterator = std::find_if(loadedThemesList.begin(), loadedThemesList.end(), [&](const Core::Theme& currentTheme){ return currentTheme == newTheme; }); iterator != loadedThemesList.end()) {
                // log тема уже присутствует
                return;
            }
            this->loadedThemesList.push_back(std::move(newTheme));
            // log тема загружена
        }
        // log загрузка тем завершена + количество
    }

    void ThemeStorageProvider::loadThemes(Directory themeDirectory) {

        std::ifstream ThemeFile(std::move(themeDirectory), std::ios::in);
        if (!ThemeFile.is_open()) throw std::ios::failure("Open ThemeFile error");
        nlohmann::json themeTemp;

        try {
            ThemeFile >> themeTemp;
        } catch (const nlohmann::json::parse_error& parse_error){
            ThemeFile.close();
            throw std::runtime_error("parse error");
        }
        ThemeFile.close();

        Counter toLoadThemesCount{};
        Counter loadedThemesCount{};

        for (const auto& [themeName, themeJson]: themeTemp.items()) {
            ++toLoadThemesCount;
            if (!validateThemeName(themeName)) continue;

            Core::Theme newTheme;
            newTheme.name = themeName;

            using namespace ftxui;
            Check validateError = false;
            for (const auto& row : themeJson.items()) {
                if (!row.value().is_number_integer()) { validateError = true; break; }

                ColorID colorId = row.value().get<short>();

                if (row.key() == TEXT_BASE)                 newTheme.text_base              = Color::Palette256(validateColor(colorId));
                else if (row.key() == TEXT_PRIMARY)         newTheme.text_primary           = Color::Palette256(validateColor(colorId));
                else if (row.key() == TEXT_SECONDARY)       newTheme.text_secondary         = Color::Palette256(validateColor(colorId));
                else if (row.key() == TEXT_ERROR)           newTheme.text_error             = Color::Palette256(validateColor(colorId));
                else if (row.key() == TEXT_SUCCESS)         newTheme.text_success           = Color::Palette256(validateColor(colorId));
                else if (row.key() == TEXT_WARNING)         newTheme.text_warning           = Color::Palette256(validateColor(colorId));
                else if (row.key() == TEXT_INFO)            newTheme.text_info              = Color::Palette256(validateColor(colorId));
                else if (row.key() == TEXT_ACCENT)          newTheme.text_accent            = Color::Palette256(validateColor(colorId));
                else if (row.key() == BG_BASE)              newTheme.bg_base                = Color::Palette256(validateColor(colorId));
                else if (row.key() == BG_PRIMARY)           newTheme.bg_primary             = Color::Palette256(validateColor(colorId));
                else if (row.key() == BG_SECONDARY)         newTheme.bg_secondary           = Color::Palette256(validateColor(colorId));
                else if (row.key() == BG_SELECTED)          newTheme.bg_selected            = Color::Palette256(validateColor(colorId));
                else if (row.key() == BG_ACTIVE)            newTheme.bg_active              = Color::Palette256(validateColor(colorId));
                else if (row.key() == BORDER_WINDOW)        newTheme.border_window          = Color::Palette256(validateColor(colorId));
                else if (row.key() == BORDER_PRIMARY)       newTheme.border_primary         = Color::Palette256(validateColor(colorId));
                else if (row.key() == BORDER_FOCUSED)       newTheme.border_focused         = Color::Palette256(validateColor(colorId));
                else if (row.key() == BUTTON_STYLE)         newTheme.button_style           = ftxui::nothing;
                else if (row.key() == BUTTON_FOCUSED)       newTheme.button_focused         = ftxui::inverted;
                else if (row.key() == TEXT_WINDOW_HEADER)   newTheme.text_window_header     = Color::Palette256(validateColor(colorId));
                else if (row.key() == BORDER_WINDOW_HEADER) newTheme.border_window_header   = Color::Palette256(validateColor(colorId));
                else {
                    // log не загрузилась тема
//                    throw std::invalid_argument("Invalid argument in json (" + appSettings->getThemeDirectory() + "): [" + row.key() + "]");
                    return;
                }
            }
            if (validateError) {
                // log тема не загружена
                break;
            }

            if (auto iterator = std::find_if(loadedThemesList.begin(), loadedThemesList.end(), [&](const Core::Theme& currentTheme){ return currentTheme == newTheme; }); iterator != loadedThemesList.end()) {
                // log тема уже присутствует
                return;
            }
            this->loadedThemesList.push_back(std::move(newTheme));
            ++loadedThemesCount;
            // log тема загружена
        }
        // log загрузка тем завершена + количество
    }

    std::vector<Core::Theme> ThemeStorageProvider::getLoadedThemeList() const {
        return this->loadedThemesList;
    }

    ColorID ThemeStorageProvider::validateColor(ColorID colorId) {
        if (!(colorId < 0 || colorId > 255)) return colorId;
        return 9; // text_error color
    }

    Check ThemeStorageProvider::validateThemeName(const std::string &themeName) {
        std::string toLowerDuplicate = themeName;
        std::transform(toLowerDuplicate.begin(), toLowerDuplicate.end(), toLowerDuplicate.begin(), [](auto letter){ return static_cast<char>(std::tolower(letter));} );
        if (toLowerDuplicate == "default") return false;
        return true;
    }

    void ThemeStorageProvider::saveThemes(std::vector<Core::Theme> themesTM) {
        std::ofstream ThemeFile(ThemeDirectory);
        if (!ThemeFile.is_open()) {
            throw std::ios::failure("Save file open error");
        }

        nlohmann::json JsonToFile;

        Counter toSaveThemesCount{};
        Counter savedThemesCount{};

        for (const Core::Theme& theme: themesTM) {
            ++toSaveThemesCount;
            if (theme.empty()) continue;

            nlohmann::json themeDetails;

            themeDetails[TEXT_BASE]              = getPaletteIndex(theme.text_base);
            themeDetails[TEXT_PRIMARY]           = getPaletteIndex(theme.text_primary);
            themeDetails[TEXT_SECONDARY]         = getPaletteIndex(theme.text_secondary);
            themeDetails[TEXT_ERROR]             = getPaletteIndex(theme.text_error);
            themeDetails[TEXT_SUCCESS]           = getPaletteIndex(theme.text_success);
            themeDetails[TEXT_WARNING]           = getPaletteIndex(theme.text_warning);
            themeDetails[TEXT_INFO]              = getPaletteIndex(theme.text_info);
            themeDetails[TEXT_ACCENT]            = getPaletteIndex(theme.text_accent);
            themeDetails[BG_BASE]                = getPaletteIndex(theme.bg_base);
            themeDetails[BG_PRIMARY]             = getPaletteIndex(theme.bg_primary);
            themeDetails[BG_SECONDARY]           = getPaletteIndex(theme.bg_secondary);
            themeDetails[BG_SELECTED]            = getPaletteIndex(theme.bg_selected);
            themeDetails[BG_ACTIVE]              = getPaletteIndex(theme.bg_active);
            themeDetails[BORDER_WINDOW]          = getPaletteIndex(theme.border_window);
            themeDetails[BORDER_PRIMARY]         = getPaletteIndex(theme.border_primary);
            themeDetails[BORDER_FOCUSED]         = getPaletteIndex(theme.border_focused);
            themeDetails[TEXT_WINDOW_HEADER]     = getPaletteIndex(theme.text_window_header);
            themeDetails[BORDER_WINDOW_HEADER]   = getPaletteIndex(theme.border_window_header);
            themeDetails[BUTTON_STYLE] = -8;
            themeDetails[BUTTON_FOCUSED] = -9;

            JsonToFile[theme.name] = std::move(themeDetails);
        }

        ThemeFile << JsonToFile.dump(4);
        ThemeFile.close();

    }

    ColorID ThemeStorageProvider::getPaletteIndex(const Color &color) {
        for (ColorID i = 0; i <= 255; ++i) {
            ftxui::Color candidate(static_cast<ftxui::Color::Palette256>(i));
            if (color == candidate) return i;
        }
        return -1;
    }
}