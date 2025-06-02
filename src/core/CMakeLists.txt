add_library(core STATIC
        ThemeManager.cpp
        ../../include/core/ThemeManager.h
        ../../include/core/Signal.cpp
        ../../include/core/Signal.h
        ../../include/core/Signal2.h
)
find_package(Boost 1.88 CONFIG REQUIRED COMPONENTS signals2)

target_link_libraries(core PUBLIC
        ftxui::screen
        ftxui::dom
        ftxui::component
        Boost::signals2
        utils
)

target_include_directories(core PUBLIC ../../include)