//
// Created by hid3h on 26.05.2025.
//

#ifndef STAFFDEMO_USERINTERFACE_H
#define STAFFDEMO_USERINTERFACE_H
#include "../core/Signal2.h"
#include "../core/ThemeManager.h"
#include "AppSetting.h"
#include "ScreenManager.h"
#include "memory"
#include "ftxui/component/screen_interactive.hpp"
#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>

#include "View/StartScreenView.h"
#include "ViewModel/StartScreenViewModel.h"

#include "../Data/CSV/CSVStaffRepository.h"
#include "../Data/CSV/CSVProjectRepository.h"


///@defgroup TextUserInterface Текстовый пользовательский интерфейс


namespace StaffDemo::UI {
    ///@brief
    ///@details
    ///@ingroup TextUserInterface
    class UserInterface {
    private:
//        void InitLogger();
        void InitBoostLogger();
        void InitThemes();
        void InitModels();
        void InitScreens();
        void ConnectSignals();

        ftxui::ScreenInteractive screenInteractive;
        ScreenManager screenManager;
        std::shared_ptr<AppSettings> appSettings;


        std::shared_ptr<Interface::IStaffRepository> staffRepository = std::make_shared<Repository::CSVStaffRepository>();
        std::shared_ptr<Interface::IProjectRepository> projectRepository = std::make_shared<Repository::CSVProjectRepository>();


        Core::Connection<void()> startScreenSignalConnection;


        std::shared_ptr<Model::StartScreenViewModel> startScreenViewModel;

    public:
        UserInterface();
        ~UserInterface();

        void run();
    };

} // UI
// StaffDemo

#endif //STAFFDEMO_USERINTERFACE_H
