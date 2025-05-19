cmake_minimum_required(VERSION 3.30)
project(StaffDemo)
set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

# Зависимости
FetchContent_Declare(
        fmt GIT_REPOSITORY https://github.com/fmtlib/fmt.git GIT_TAG 10.2.1
)
FetchContent_Declare(
        tabulate GIT_REPOSITORY https://github.com/p-ranav/tabulate.git GIT_TAG master
)
FetchContent_Declare(
        ftxui GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui GIT_TAG main
)
FetchContent_MakeAvailable(fmt tabulate ftxui)

# Подмодули проекта
add_subdirectory(src/core)
add_subdirectory(src/staff)
add_subdirectory(src/utils)
add_subdirectory(src/ui)
add_subdirectory(Google_Tests)

add_executable(StaffDemo main.cpp)
target_link_libraries(StaffDemo
        PRIVATE
        core
        staff
        logger
        ui
        GoogleTests
        fmt::fmt
        tabulate::tabulate
        ftxui::screen
        ftxui::dom
        ftxui::component
)