add_library(ui STATIC
        ../../include/ui/UserInterface.h
        UserInterface.cpp
        ../../include/core/Theme.h
        ../../include/ui/AppSetting.h
        ViewModel/ViewModelBase.cpp
        ../../include/ui/ViewModel/ViewModelBase.h
        View/ViewBase.cpp
        ../../include/ui/View/ViewBase.h
        ScreenManager.cpp
        ../../include/ui/ScreenManager.h
        ../../include/ui/enumScreen.h
        ViewModel/StartScreenViewModel.cpp
        ../../include/ui/ViewModel/StartScreenViewModel.h
        View/StartScreenView.cpp
        ../../include/ui/View/StartScreenView.h
        ../../include/ui/View/LoadEmployeeView.cpp
        ../../include/ui/View/LoadEmployeeView.h
        ../../include/ui/ViewModel/LoadEmployeeViewModel.cpp
        ../../include/ui/ViewModel/LoadEmployeeViewModel.h
)

find_package(Boost 1.88 REQUIRED COMPONENTS signals2 log log_setup system filesystem date_time thread)

target_link_libraries(ui PUBLIC
        ftxui::screen
        ftxui::dom
        ftxui::component
        Boost::signals2
        Boost::log
        Boost::log_setup
        utils
        Boost::system
        Boost::filesystem
        Boost::date_time
        Boost::thread
        core
)
target_include_directories(ui PUBLIC ../include)
