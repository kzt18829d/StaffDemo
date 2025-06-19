#ifndef STAFFDEMO_APPSETTING_H
#define STAFFDEMO_APPSETTING_H
#include "string"
#include "algorithm"
#include "ctime"
#include "staff/IEmployee.h"
#include "../core./Usages.h"
#include "../utils/FileTimeStamp.h"
#include "../data/ThemeStorageProvider.h"
#include "../core/ThemeManager.h"
#include "../core/TranslationManager.h"
#include "../Data/TranslationStorageProvider.h"



///@defgroup Core Ядро

///@namespace Core
namespace Core {

    ///@brief Класс общих настроек приложения
    ///@details Класс общих настроек приложения, содержащий в себе данные путей, размеры окна, методы для их получения и изменения.
    /// Так же хранит в себе провайдер тем и репозитории.
    ///@ingroup Core
    class AppSettings {
    private:
        Directory LocalizationDirectory;
        Directory ThemeDirectory;
        Directory StaffDirectory;
        Directory StaffDirectory_custom;
        Directory LogDirectory;
        Directory LoggerSettings;

        Size ScreenWidth {120};
        Size ScreenHeight {30};

        Language currentLanguage;

        Check UseCustom {false};
        Check loadThemes {false};
    public:

        [[nodiscard]] Directory getLocalizationDirectory() const  { return this->LocalizationDirectory; }
        [[nodiscard]] Directory getThemeDirectory() const         { return this->ThemeDirectory; }
        [[nodiscard]] Directory getStaffDirectory() const         { if (!UseCustom || StaffDirectory_custom.empty()) return this->StaffDirectory; else return this-> StaffDirectory_custom; }
        [[nodiscard]] Directory getLogDirectory() const           { return this->LogDirectory; }

        [[nodiscard]] Size getScreenWidth() const                 { return this->ScreenWidth; }
        [[nodiscard]] Size getScreenHeight() const                { return this->ScreenHeight; }

        [[nodiscard]] Language getCurrentLanguage() const         { return this->currentLanguage; }

        [[nodiscard]] Check getUseCustom() const                  { return this->UseCustom; }
        [[nodiscard]] Check getLoadThemes() const                 { return this->loadThemes; }

        void SetBaseWidthHeight()                                 { this->ScreenHeight = 30; this->ScreenWidth = 120; }
        void setScreenWidth(Size Width)                           { this->ScreenWidth = Width; }
        void setScreenHeight(Size Height)                         { this->ScreenHeight = Height; }

        void setStaffDirectory(Directory& newDirectory)           { this->StaffDirectory_custom = std::move(newDirectory); }


        std::unique_ptr<Data::ThemeStorageProvider> themeStorageProvider;
        std::unique_ptr<Data::TranslationStorageProvider> translationStorageProvider;
        std::unique_ptr<Core::ThemeManager> themeManager;
        std::unique_ptr<Core::TranslationManager> translationManager;

        AppSettings() {
#ifdef NDEBUG
            LocalizationDirectory       = "./localization.json";
            ThemeDirectory              = "./themes.json";
            StaffDirectory              = "./Staff_Data.csv";
            LogDirectory                = "./logs/log-" + Utils::getTime();
            LoggerSettings              = "./logger.ini";
            loadThemes                  = true;
#else
            LocalizationDirectory       = "./Data_local/newLangs.json";
            ThemeDirectory              = "./Data_local/themes.json";
            StaffDirectory              = "./Data_local/Staff_Data.csv";
            LogDirectory                = "./Data_local/logs/log-" + Utils::getTime();
            LoggerSettings              = "./Data_local/logger.ini";
            loadThemes                  = false;
#endif
            currentLanguage = "en";
            themeStorageProvider        = std::make_unique<Data::ThemeStorageProvider>(this->ThemeDirectory);
            translationStorageProvider  = std::make_unique<Data::TranslationStorageProvider>(this->LocalizationDirectory);
            themeManager                = std::make_unique<Core::ThemeManager>();
            translationManager          = std::make_unique<Core::TranslationManager>(this->currentLanguage);

        } // AppSettings

        ~AppSettings() = default;

    };
}


#endif //STAFFDEMO_APPSETTING_H
