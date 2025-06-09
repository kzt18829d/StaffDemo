#include "../../include/ui/UserInterface.h"

namespace UI {
    void UserInterface::initModels() {
        appSettings = std::make_shared<Core::AppSettings>();
    }

    void UserInterface::initScreens() {

        startScreenViewModel = std::make_shared<ViewModel::StartScreenViewModel>(appSettings);
        auto startScreenView = std::make_shared<View::StartScreenView>(startScreenViewModel);
        screenManager.addScreen(WindowType::START_WINDOW, startScreenView);
        screenManager.showScreen(WindowType::START_WINDOW); //!!!!!!!!!!!!!!!

        employeeLoadScreenAutoViewModel = std::make_shared<ViewModel::EmployeeLoadScreenAutoViewModel>(appSettings);
        auto employeeLoadScreenView = std::make_shared<View::EmployeeLoadScreenAutoView>(employeeLoadScreenAutoViewModel);
        screenManager.addScreen(WindowType::LOAD_EMPLOYEES_WINDOW_auto, employeeLoadScreenView);

    }

    void UserInterface::connectSignals() {
        StartScreenSignalConnection = startScreenViewModel->applySettingsSignal.connect([this](WindowType nextScreen){screenManager.showScreen(nextScreen);});
    }

    UserInterface::UserInterface() : screenInteractive(ftxui::ScreenInteractive::TerminalOutput()) {
        initModels();
//        initLogger();
        loadThemes();
        initThemes();
        loadTranslate();
        initTranslate();
        initScreens();
        connectSignals();
    }

    void UserInterface::run() {
        screenInteractive.Loop(screenManager.getActiveScreenComponent());
    }

    void UserInterface::initLogger() {

    }

    void UserInterface::initThemes() {
        const bool t = false;
        if constexpr (!t) {
            return;
        } else {
            auto themes = appSettings->themeStorageProvider->getLoadedThemeList();
            if (themes.empty()) return;
            for (Core::Theme &theme: themes) appSettings->themeManager->addTheme(theme);
        }

    }

    void UserInterface::loadThemes() {
        const bool t = false;
        if constexpr (!t) {
            return;
        }
        if (!appSettings->getLoadThemes()) return;
        appSettings->themeStorageProvider->loadThemes();
    }

    void UserInterface::loadTranslate() {
        appSettings->translationStorageProvider->loadFromJSON();
    }

    void UserInterface::initTranslate() {
        auto translateFile = appSettings->translationStorageProvider->getLanguagePack();
        appSettings->translationManager->loadLocalization(translateFile);
    }

    UserInterface::~UserInterface() = default;

}