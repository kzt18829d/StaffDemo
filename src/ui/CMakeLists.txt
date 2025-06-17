add_library(ui STATIC
        ../../include/ui/UserInterface.h
        UserInterface.cpp
        ../../include/core/Theme.h
        ../../include/core/AppSetting.h
        ScreenManager.cpp
        ../../include/ui/ScreenManager.h
        ViewModel/BasicViewModel.cpp
        ../../include/ui/ViewModel/BasicViewModel.h
        ViewModel/StartScreenViewModel.cpp
        ../../include/ui/ViewModel/StartScreenViewModel.h
        View/BasicView.cpp
        ../../include/ui/View/BasicView.h
        View/StartScreenView.cpp
        ../../include/ui/View/StartScreenView.h
        ViewModel/EmployeeLoadScreenAutoViewModel.cpp
        ../../include/ui/ViewModel/EmployeeLoadScreenAutoViewModel.h
        View/EmployeeLoadScreenAutoView.cpp
        ../../include/ui/View/EmployeeLoadScreenAutoView.h
        Model/loadEmployeeLogModel.cpp
        ../../include/ui/Model/loadEmployeeLogModel.h
        ViewModel/BaseScreenViewModel.cpp
        ../../include/ui/ViewModel/BaseScreenViewModel.h
        View/BaseScreenView.cpp
        ../../include/ui/View/BaseScreenView.h
        View/BaseScreenSubViews/SettingsSubView.cpp
        ../../include/ui/View/BaseScreenSubViews/SettingsSubView.h
        ViewModel/BaseScreenSubViewModels/SettingsSubViewModel.cpp
        ../../include/ui/ViewModel/BaseScreenSubViewModel/SettingsSubViewModel.h
)

find_package(Boost REQUIRED COMPONENTS signals2
        #filesystem log log_setup date_time thread system
)


target_link_libraries(ui PUBLIC
        ftxui::screen
        ftxui::dom
        ftxui::component
        Boost::signals2
        utils
        core
        data
        fmt::fmt
        #Boost::filesystem
        #Boost::log
        #Boost::log_setup
        #Boost::date_time
        #Boost::thread
        #Boost::system
)
target_include_directories(ui PUBLIC ../include)
