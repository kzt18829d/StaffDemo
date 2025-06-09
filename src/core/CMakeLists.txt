add_library(core STATIC
        ../../include/core/Theme.h
        ThemeManager.cpp
        ../../include/core/ThemeManager.h
        ../../include/core/Signal.h
        ../../include/core/Usages.h
        ../../include/core/ScreensENUM.h
)

#find_package(boost_date_time CONFIG REQUIRED)
find_package(Boost REQUIRED COMPONENTS signals2)

target_link_libraries(core PUBLIC
        ftxui::screen
        ftxui::dom
        ftxui::component
        Boost::signals2
        utils
)

target_include_directories(core PUBLIC ../../include)