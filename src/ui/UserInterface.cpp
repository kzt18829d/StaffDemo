
#ifndef DEBUG
#define DEBUG_PARAM_
#endif

#include "../../include/ui/UserInterface.h"

namespace UI {
    void UserInterface::initModels() {
        appSettings = std::make_shared<Core::AppSettings>();
        repositoryInstruments = std::make_shared<Core::RepositoryInstruments>();
    }

    void UserInterface::initScreens() {

        startScreenViewModel = std::make_shared<ViewModel::StartScreenViewModel>(appSettings);
        auto startScreenView = std::make_shared<View::StartScreenView>(startScreenViewModel);
        screenManager.addScreen(WindowType::START_WINDOW, startScreenView);

        employeeLoadScreenAutoViewModel = std::make_shared<ViewModel::EmployeeLoadScreenAutoViewModel>(appSettings);
        auto employeeLoadScreenView = std::make_shared<View::EmployeeLoadScreenAutoView>(employeeLoadScreenAutoViewModel);
        screenManager.addScreen(WindowType::LOAD_EMPLOYEES_WINDOW_auto, employeeLoadScreenView);


        // Base Screen ----------------------------

        // Settings Screen
        baseScreen_SettingsSubviewModel = std::make_shared<ViewModel::SubViewModel::SettingsSubViewModel>(appSettings, repositoryInstruments);
        auto baseScreen_SettingsSubview = std::make_shared<View::SubView::SettingsSubView>(baseScreen_SettingsSubviewModel);

        // Base Screen
        baseScreenViewModel = std::make_shared<ViewModel::BaseScreenViewModel>(appSettings);
        auto baseScreenView = std::make_shared<View::BaseScreenView>(baseScreenViewModel, baseScreen_SettingsSubview);
        screenManager.addScreen(WindowType::BASE_WINDOW, baseScreenView);


#ifdef DEBUG_PARAM_
        auto TYPESCREEN = WindowType::START_WINDOW;
        screenManager.showScreen(TYPESCREEN); //!!!!!!!!!!!!!!!
#else
        screenManager.showScreen(WindowType::START_WINDOW);
#endif
    }

    void UserInterface::connectSignals() {
        appSettings->themeManager->ThemeChangedSignal.connect([&,this](Core::Theme tm){
            appSettings->themeManager->setTheme(tm.name);
            screenInteractive.PostEvent(Event::Custom);
        });

        StartScreenStatusMessageChangedConnection= startScreenViewModel->statusMessageChangedSignal.connect([&, this](Message&){
           screenInteractive.PostEvent(Event::Custom);
        });

        ChangeScreenFromStartScreenConnection = startScreenViewModel->applySettingsSignal.connect([&, this](WindowType nextScreen){
            screenManager.showScreen(nextScreen);
//            screenInteractive.PostEvent(Event::Custom);
            screenInteractive.ExitLoopClosure();
//            screenInteractive.Exit();
            run();
        });

        ChangeScreenFromEmployeeLoadScreenAutoConnection = employeeLoadScreenAutoViewModel->saveAndGoBaseWindowSignal.connect([&, this](WindowType nextScreen){
            screenManager.showScreen(nextScreen);
            screenInteractive.ExitLoopClosure();
//            screenInteractive.Exit();
            run();
        });

        ViewUpdateRequestConnection = baseScreenViewModel->ViewUpdateSignal.connect([&, this]{screenInteractive.PostEvent(Event::Custom);});

        exitSignalConnection = baseScreenViewModel->exitSignal.connect([&, this]{
           screenInteractive.ExitLoopClosure();
           screenInteractive.Exit();
           exit(0);
        });
    }

    UserInterface::UserInterface() : screenInteractive(ftxui::ScreenInteractive::TerminalOutput()) {
//        initLogger();
        initModels();
        loadThemes();
        initThemes();
        loadTranslate();
        initTranslate();
        initScreens();
        connectSignals();
    }

    void UserInterface::run() {
        screenInteractive.ExitLoopClosure();
        screenInteractive.Loop(screenManager.getActiveScreenComponent());
    }

    void UserInterface::initLogger() {

//        namespace logging = boost::log;
//        namespace src = boost::log::sources;
//        namespace sinks = boost::log::sinks;
//        namespace expr = boost::log::expressions;
//        namespace keywords = boost::log::keywords;
//
//        boost::log::add_common_attributes();
//
//        auto file_backend = boost::make_shared<sinks::text_file_backend>(
//               keywords::file_name = "StaffDemo_LOG_%Y-%m-%d_%H-%M-%S.txt",
//                boost::log::keywords::file_name = "StaffDemo_LOG_%Y-%m-%d_%H-%M-%S.log",
//                keywords::rotation_size = 100 * 1024 * 1024,
//                keywords::time_based_rotation = boost::log::sinks::file::rotation_at_time_interval(boost::posix_time::hours(1)),
//                keywords::auto_flush = true);
//
//
//        using sink_t = sinks::asynchronous_sink<sinks::text_file_backend>;
//        auto sinkFile = boost::make_shared<sink_t>(file_backend);
//
//        sinkFile->set_formatter(
//                expr::stream << "[" << expr::format_date_time<boost::posix_time::ptime>("TimeStamp", "%H:%M:%S") << "]"
//                << "[" << logging::trivial::severity << "]"
//                << ": " << expr::smessage
//                );
//
//#ifdef DEBUG_PARAM_
//        sinkFile->set_filter(logging::trivial::severity >= logging::trivial::trace);
//#else
//        sinkFile->set_filter(logging::trivial::severity >= logging::trivial::info);
//#endif
//        logging::core::get()->add_sink(sinkFile);
    }

    void UserInterface::initThemes() {
#ifdef DEBUG_PARAM_
        // log
#else
        auto themes = appSettings->themeStorageProvider->getLoadedThemeList();
        if (themes.empty()) return;
        for (Core::Theme &theme: themes) appSettings->themeManager->addTheme(theme);
#endif
    }

    void UserInterface::loadThemes() {
#ifdef DEBUG_PARAM_
        //log
#else
        if (!appSettings->getLoadThemes()) return;
        appSettings->themeStorageProvider->loadThemes();
#endif
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