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
#include "Functions.h"

namespace TUI {
    using TableRow = std::pair<std::string, std::string>;
    using TableData = std::vector<TableRow>;

    namespace LOCAL {
//        template <typename ...Args>
        TableData CreateTable(const TempEmloyee& tempE);
        void N_A_DEF(TempEmloyee &temp);
    }

    char START_SCREEN(const std::size_t& wWidth, const std::size_t& wHeight, std::string& DIRECTORY);
    void LOAD_SCREEN(const std::size_t& wWidth, const std::size_t& wHeight, const std::string& DIRECTORY, std::unordered_map<std::string, std::shared_ptr<Employee>>&STAFF, std::unordered_multimap<std::string, std::shared_ptr<Project>>&PROJECT_LIST);
}

#endif //STAFFDEMO_TUI_H
