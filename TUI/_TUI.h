#ifndef STAFFDEMO__TUI_H
#define STAFFDEMO__TUI_H
#include <iostream>
#include <string>
#include <fmt/core.h>
#include <unordered_map>
#include <vector>
#include <Employee.h>
#include "Factory.h"
#include "Functions.h"
namespace Text {
    const std::string mTitle(" StaffDemo ");
    const std::string fTitle(" Staff Management System ");
}


namespace _fTUI {

    void fillVoid(const std::string& height, const std::size_t& width, std::size_t& curseH, const std::size_t& MAX_HEIGHT);
    void fillVoid(std::size_t height, const std::size_t& width, std::size_t& curseH, const std::size_t& MAX_HEIGHT);
    void M_TITLE(std::size_t width=100);
    void F_TITLE(std::size_t width=100);

}
namespace _TUI{
    void clean(std::size_t x=1, std::size_t y=1);
    void moveCursor(std::size_t row, std::size_t column);

    char START_SCREEN(const std::size_t& wWight, const std::size_t& wHeight);
    auto LOAD_EMP_SCREEN(const std::size_t& wWight, const std::size_t& wHeight, std::unordered_map<std::string, std::unique_ptr<Employee>>&STAFF, std::unordered_multimap<std::string, Project*>&PROJECT_LIST);

}


#endif //STAFFDEMO__TUI_H
