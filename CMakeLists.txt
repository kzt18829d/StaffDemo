cmake_minimum_required(VERSION 3.30)
project(StaffDemo)

set(CMAKE_CXX_STANDARD 20)

add_executable(StaffDemo main.cpp
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
        CustomLib/TextEdit.cpp
        CustomLib/TextEdit.h
)
