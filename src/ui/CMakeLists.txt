add_library(ui STATIC
        ../../include/ui/UserInterface.h
        UserInterface.cpp
        ../../include/core/Theme.h
        ../../include/core/AppSetting.h
        ScreenManager.cpp
        ../../include/ui/ScreenManager.h
        ../../include/ui/ViewModel/BasicViewModel.cpp
        ../../include/ui/ViewModel/BasicViewModel.h
        ../../include/ui/ViewModel/StartScreenViewModel.cpp
        ../../include/ui/ViewModel/StartScreenViewModel.h
        ../../include/ui/View/BasicView.cpp
        ../../include/ui/View/BasicView.h
        ../../include/ui/View/StartScreenView.cpp
        ../../include/ui/View/StartScreenView.h
        ../../include/ui/ViewModel/EmployeeLoadScreenAutoViewModel.cpp
        ../../include/ui/ViewModel/EmployeeLoadScreenAutoViewModel.h
        ../../include/ui/View/EmployeeLoadScreenAutoView.cpp
        ../../include/ui/View/EmployeeLoadScreenAutoView.h
        ../../include/ui/Model/loadEmployeeLogModel.cpp
        ../../include/ui/Model/loadEmployeeLogModel.h
        ../../include/ui/ViewModel/BaseScreenViewModel.cpp
        ../../include/ui/ViewModel/BaseScreenViewModel.h
        ../../include/ui/View/BaseScreenView.cpp
        ../../include/ui/View/BaseScreenView.h
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
