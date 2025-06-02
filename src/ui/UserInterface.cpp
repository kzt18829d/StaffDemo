//
// Created by hid3h on 26.05.2025.
//

#include "../../include/ui/UserInterface.h"

namespace StaffDemo::UI {


    UserInterface::UserInterface() : screenInteractive(ftxui::ScreenInteractive::TerminalOutput()) {
        StaffDemo::Utils::TranslationManager::instance().loadJson(appSettings->localizationDataDirectory, "en");
//        StaffDemo::Core::ThemeManager::instance().setTheme("Default");
        InitBoostLogger();
//        LOG_INFO << "UserInterface load";
        InitThemes();
        InitModels();
        InitScreens();
        ConnectSignals();
//        LOG_INFO << "UserInterface loaded.";
    }

    void UserInterface::InitBoostLogger() {
        boost::log::add_common_attributes();
        boost::log::add_file_log(
                boost::log::keywords::file_name = "StaffDemo_log-%N.log",
                boost::log::keywords::rotation_size = 40'000'000,
//                boost::log::keywords::time_based_rotation = boost::log::sinks::file::rotation_at_time_point(0, 0, 0),
                boost::log::keywords::format = "[%TimeStamp%] [&ThreadID%] [%Severity%] %Message%",
                boost::log::keywords::auto_flush = true
        );
//        boost::log::core::get()->set_filter(boost::log::trivial::severity >= boost::log::trivial::info);
//        LOG_INFO << "Logging initialized.";
    }

    void UserInterface::InitThemes() {
        StaffDemo::Core::ThemeManager::instance().setTheme("Default");
//        LOG_INFO << "Themes initialized. Current theme: " << Core::ThemeManager::instance().getTheme().name;
    }

    void UserInterface::InitModels() {
        appSettings = std::make_shared<AppSettings>();

//        LOG_INFO << "Models initialized.";
    }

    void UserInterface::InitScreens() {
//        LOG_INFO << "Initializing screens...";

        startScreenViewModel = std::make_shared<Model::StartScreenViewModel>(appSettings);
        auto startScreenView = std::make_shared<View::StartScreenView>(startScreenViewModel);
        screenManager.addScreen("StartScreen", startScreenView);

        if (screenManager.getActiveScreenName() != "StartScreen") {
//            LOG_FATAL << "Failed to switch to initial screen 'StartScreen'";
            exit(69);
        }
//        LOG_INFO << "Screens initialized. Current screen: " << screenManager.getActiveScreenName();
    }

    void UserInterface::ConnectSignals() {
        if (startScreenViewModel) {
            startScreenSignalConnection = startScreenViewModel->applySettingSignal.connect([this]() {
//                LOG_INFO << "StartScreen settings applied. Switching to next screen (e.g., BaseWindow).";
            });

        }
    }

    UserInterface::~UserInterface() {
//        LOG_INFO << "UserInterface destructing...";
        if (startScreenSignalConnection.connected()) {
            startScreenSignalConnection.disconnect();
        }

//        LOG_INFO << "UserInterface destructed.";
    }

    void UserInterface::run() {
//        LOG_INFO << "UserInterface run loop started.";
        screenInteractive.Loop(screenManager.getActiveScreenComponent());
//        LOG_INFO << "UserInterface run loop finished.";
    }
}
// UI
// StaffDemo