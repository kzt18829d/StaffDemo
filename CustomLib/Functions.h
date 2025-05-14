#ifndef STAFFDEMO_FUNCTIONS_H
#define STAFFDEMO_FUNCTIONS_H

#include <random>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <fstream>
#include <sstream>
#include <memory>
#include <functional>
#include "cstring"
#include <fmt/core.h>
#include <tabulate/table.hpp>

#include <TUI.h>

#include "Employee.h"
#include "Personal.h"
#include "Engineer.h"
#include "Manager.h"
namespace GEN {

    std::string genid();
    std::string genid(int lenght, bool num_token=true, bool let_token=true);

}

namespace File {

    inline std::vector<std::string>split(const std::string& line, char delim=';');
    inline std::set<std::string>splitUnic(const std::string& line, char delim=':') noexcept;

    void createFile(const std::string& dir);
    void openFile(const std::string& dir);

    void saveSCV(const std::string& directory, const std::unordered_map<std::string, std::shared_ptr<Employee>>&STAFF_LIST,
                 const std::unordered_multimap<std::string, std::shared_ptr<Project>>&PROJECT_LIST, char delim=';', char projectDelim=':');

    std::queue<TempEmloyee> loadSCV(const std::string& directory);

}

namespace Employees {

    void CreateEmployeePointers(const TempEmloyee &temp, std::unordered_map<std::string, std::shared_ptr<Employee>> &STAFF,
                                                                   std::unordered_map<std::string, std::shared_ptr<Project>> &PROJECT_LIST);
}

#endif //STAFFDEMO_FUNCTIONS_H
