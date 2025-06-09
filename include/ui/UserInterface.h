#ifndef STAFFDEMO_USERINTERFACE_H
#define STAFFDEMO_USERINTERFACE_H

#include "../core/ThemeManager.h"
#include "core/AppSetting.h"
#include "data/ThemeStorageProvider.h"
#include "ScreenManager.h"
#include "memory"
#include "ftxui/component/screen_interactive.hpp"


#include "../core/ScreensENUM.h"

// include ViewModels
#include "ViewModel/StartScreenViewModel.h"
#include "ViewModel/EmployeeLoadScreenAutoViewModel.h"


// include Views
#include "ui/View/StartScreenView.h"
#include "View/EmployeeLoadScreenAutoView.h"


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

        ftxui::ScreenInteractive screenInteractive;

        ScreenManager screenManager;

        std::shared_ptr<Core::AppSettings> appSettings;

        boost::signals2::connection StartScreenSignalConnection;

        boost::signals2::connection EmployeeLoadScreenAutoConnection;
        boost::signals2::connection EmployeeLoadScreenHandConnection;

        std::shared_ptr<ViewModel::StartScreenViewModel> startScreenViewModel;
        std::shared_ptr<ViewModel::EmployeeLoadScreenAutoViewModel> employeeLoadScreenAutoViewModel;

    public:
        UserInterface();
        ~UserInterface();

        void run();
    };

} // UI

#endif //STAFFDEMO_USERINTERFACE_H
