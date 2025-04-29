//
// Created by hid3h on 28.04.2025.
//

#ifndef STAFFDEMO_GRAPHICS_H
#define STAFFDEMO_GRAPHICS_H
#include <iostream>
#include "fmt/core.h"

std::string mTitle(" StaffDemo "), fTitle(" Staff Management System ");

void M_TITLE(std::size_t width=100) {
    std::cout << fmt::format("+{:=^{}}+", mTitle, width) << std::endl;
}

void F_TITLE(std::size_t width=100) {
    std::cout << fmt::format("+{:=^{}}+", fTitle, width) << std::endl;
}

#endif //STAFFDEMO_GRAPHICS_H
