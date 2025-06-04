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
add_subdirectory(src/Data)
add_subdirectory(src/core)
add_subdirectory(src/staff)
add_subdirectory(src/utils)
add_subdirectory(src/ui)
add_subdirectory(Google_Tests)

add_executable(StaffDemo main.cpp
)

find_package(Boost 1.88 REQUIRED COMPONENTS signals2 log log_setup system filesystem thread date_time)

if(Boost_FOUND)
    message(STATUS "Boost found, version ${Boost_VERSION}")
    message(STATUS "Boost Filesystem found: ${Boost_FILESYSTEM_FOUND}")
    message(STATUS "Boost System found: ${Boost_SYSTEM_FOUND}")

    # Добавьте заголовки Boost
    target_include_directories(StaffDemo PRIVATE ${Boost_INCLUDE_DIRS})

else()
    message(FATAL_ERROR "Boost not found!")
endif()

add_compile_definitions(BOOST_USE_STATIC_LIBS)

target_link_libraries(StaffDemo
        PRIVATE
        core
        data
        staff
        ui
        GoogleTests
        fmt::fmt
        tabulate::tabulate
        ftxui::screen
        ftxui::dom
        ftxui::component
        Boost::signals2
        Boost::system
        Boost::thread
        Boost::filesystem
        Boost::log
        Boost::log_setup
        Boost::date_time
)

