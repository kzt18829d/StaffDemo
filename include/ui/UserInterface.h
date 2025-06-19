#ifndef STAFFDEMO_USERINTERFACE_H
#define STAFFDEMO_USERINTERFACE_H

#include "../core/ThemeManager.h"
#include "core/AppSetting.h"
#include "data/ThemeStorageProvider.h"
#include "ScreenManager.h"
#include "memory"
#include "ftxui/component/screen_interactive.hpp"
#include "../core/ScreensENUM.h"
#include "../core/RepositoryInstruments.h"

// include ViewModels
#include "ViewModel/StartScreenViewModel.h"
#include "ViewModel/EmployeeLoadScreenAutoViewModel.h"
#include "ViewModel/BaseScreenViewModel.h"
#include "ViewModel/BaseScreenSubViewModel/SettingsSubViewModel.h"


// include Views
#include "ui/View/StartScreenView.h"
#include "View/EmployeeLoadScreenAutoView.h"
#include "View/BaseScreenView.h"
#include "View/BaseScreenSubViews/SettingsSubView.h"


///@defgroup TextUserInterface Текстовый пользовательский интерфейс

///@namespace UI
namespace UI {
    ///@brief Главный исполнительный класс
    ///@details Главный исполнительный класс, занимающийся инициализацией данных, моделей, ViewModels, Views, и прочих
    ///@ingroup TextUserInterface
    class UserInterface {
    private:
        void initLogger();      ///< Инициализация логирования
        void loadThemes();      ///< Подгрузка тем из JSON
        void loadTranslate();   ///< Подгрузка переводов из JSON
        void initThemes();      ///< Инициализация тем в ThemeManager @see ThemeManager
        void initTranslate();   ///< Инициализация переводов в TranslationManager @see TranslationManager
        void initModels();      ///< Инициализация моделей
        void initScreens();     ///< Инициализация ViewModels&Views
        void connectSignals();  ///< Подключение глобальных сигналов

        std::thread loggerConsoleThread;

        ftxui::ScreenInteractive screenInteractive;

        ScreenManager screenManager;

        std::shared_ptr<Core::AppSettings> appSettings;
        std::shared_ptr<Core::RepositoryInstruments> repositoryInstruments;

        boost::signals2::connection ViewUpdateRequestConnection;
        boost::signals2::connection ChangeScreenFromStartScreenConnection;

        boost::signals2::connection ChangeScreenFromEmployeeLoadScreenAutoConnection;
        boost::signals2::connection ChangeScreenFromEmployeeLoadScreenHandConnection;

        boost::signals2::connection StartScreenStatusMessageChangedConnection;

        boost::signals2::connection exitSignalConnection;

        std::shared_ptr<ViewModel::StartScreenViewModel> startScreenViewModel;
        std::shared_ptr<ViewModel::EmployeeLoadScreenAutoViewModel> employeeLoadScreenAutoViewModel;
        std::shared_ptr<ViewModel::BaseScreenViewModel> baseScreenViewModel;
        std::shared_ptr<ViewModel::SubViewModel::SettingsSubViewModel> baseScreen_SettingsSubviewModel;
        std::shared_ptr<ViewModel::SubViewModel::BaseSubScreenViewModel> baseScreen_BaseSubViewModel;

    public:
        UserInterface();
        ~UserInterface();

        void run();
    };

} // UI

#endif //STAFFDEMO_USERINTERFACE_H
