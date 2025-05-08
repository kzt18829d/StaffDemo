#ifndef STAFFDEMO_TUI_H
#define STAFFDEMO_TUI_H
#include <iostream>
#include <string>
#include <ftxui/dom/elements.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/table.hpp>
#include "TranslationManager.h"
#include <unordered_map>
#include <map>
#include <memory>
#include "Employee.h"
#include "Factory.h"
#include "TranslationManager.h"

namespace TUI {
    char START_SCREEN(const std::size_t& wWidth, const std::size_t& wHeight);
    void LOAD_SCREEN(const std::size_t& wWidth, const std::size_t& wHeight, std::unordered_map<std::string, std::unique_ptr<Employee>>&STAFF, std::unordered_multimap<std::string, Project*>&PROJECT_LIST);
}


#endif //STAFFDEMO_TUI_H
