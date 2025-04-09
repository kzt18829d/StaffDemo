cmake_minimum_required(VERSION 3.30)
project(StaffDemo)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_PREFIX_PATH "D:/Qt/6.9.0/mingw_64")
find_package(Qt6 REQUIRED COMPONENTS Widgets)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR}/ui)
add_executable(StaffDemo main.cpp
        CustomLib/json.hpp
        CustomLib/Generators.h
        CustomLib/Generators.cpp
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
        ui/MainWindow.ui
        ui/MainWindow.cpp
)

target_link_libraries(StaffDemo PRIVATE Qt6::Widgets)

target_include_directories(StaffDemo PRIVATE
        ${CMAKE_CURRENT_BINARY_DIR}
)
