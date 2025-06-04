add_library(core STATIC
        ../../include/core/Theme.h
        ThemeManager.cpp
        ../../include/core/ThemeManager.h
        ../../include/core/Signal.cpp
        ../../include/core/Signal.h
        ../../include/core/Signal2.h
)
find_package(Boost 1.88 REQUIRED COMPONENTS signals2 filesystem system log log_setup date_time thread)

target_link_libraries(core PUBLIC
        ftxui::screen
        ftxui::dom
        ftxui::component
        Boost::signals2
        utils
        Boost::filesystem
        Boost::system
        Boost::log
        Boost::log_setup
        Boost::date_time
        Boost::thread
)

target_include_directories(core PUBLIC ../../include)