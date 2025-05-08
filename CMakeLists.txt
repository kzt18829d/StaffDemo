cmake_minimum_required(VERSION 3.30)
project(StaffDemo)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR}/TUI)

add_executable(StaffDemo main.cpp
        CustomLib/json.hpp
        CustomLib/Functions.h
        Sources/Personal.cpp
        Headers/Personal.h
        Sources/Employee.cpp
        Headers/Employee.h
        Sources/Engineer.cpp
        Headers/Engineer.h
        Sources/Manager.cpp
        Headers/Manager.h
        Sources/Factory.cpp
        Headers/Factory.h
        Sources/Interfaces.cpp
        Headers/Interfaces.h
        CustomLib/TranslationManager.cpp
        CustomLib/TranslationManager.h
        CustomLib/Functions.cpp
        TUI/_TUI.cpp
        TUI/_TUI.h
        TUI_FTXUI/TUI.h
        TUI_FTXUI/TUI.cpp
)


target_include_directories(StaffDemo PRIVATE
        ${CMAKE_CURRENT_BINARY_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/TUI
        ${CMAKE_CURRENT_SOURCE_DIR}/TUI_FTXUI
        ${CMAKE_CURRENT_SOURCE_DIR}/Sources
        ${CMAKE_CURRENT_SOURCE_DIR}/Headers
        ${CMAKE_CURRENT_SOURCE_DIR}/CustomLib
)

include(FetchContent)

FetchContent_Declare(
        fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt.git
        GIT_TAG 10.2.1
)
FetchContent_MakeAvailable(fmt)

FetchContent_Declare(
        tabulate
        GIT_REPOSITORY https://github.com/p-ranav/tabulate.git
        GIT_TAG master
)
FetchContent_MakeAvailable(tabulate)
FetchContent_Declare(
        ftxui
        GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
        GIT_TAG main
)
FetchContent_MakeAvailable(ftxui)

target_link_libraries(StaffDemo PRIVATE
        fmt::fmt
        tabulate::tabulate
        PRIVATE ftxui::screen
        PRIVATE ftxui::dom
        PRIVATE ftxui::component
)
