#ifndef STAFFDEMO_FUNCTIONS_H
#define STAFFDEMO_FUNCTIONS_H

#include <random>
#include <string>
#include <unordered_map>
#include <fstream>
#include <string>
#include <vector>
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

std::string genid();
std::string genid(int lenght, bool num_token=true, bool let_token=true);

template <typename T>
void saveSCV(const std::string& directory, const std::unordered_map<std::string, Employee*>&STAFF_LIST, const std::unordered_multimap<std::string, T*>&PROJECT_LIST, const char delim=';')  {
    std::ofstream file(directory);
    file << "id;name;position;salary;project\n";
    for (const auto& [id, emp]: STAFF_LIST) {
        file << emp->getID() << delim << emp->getName() << delim << emp->getPosition() << delim << emp->getPayment() << delim << PROJECT_LIST[emp->getID()].type() << '\n';
    }
}

inline std::vector<std::string>split(const std::string& line, char delim=';') {
    std::vector<std::string> result;
    std::stringstream ss(line);
    std::string value;

    while (std::getline(ss, value, delim)) result.push_back(value);
    return result;
}
//
//std::vector<std::string>split_word(const std::string& line) {
//    std::vector<std::string> result;
//    std::stringstream ss(line);
//    std::string word;
//
//    while (ss >> word) result.push_back(word);
//    return result;
//}

template <typename F>
std::pair<F, std::unique_ptr<Employee>> cEmployee(const F& param) {
//    tabulate::Table EmplInfo;
//
//    EmplInfo.add_row(fmt::format("Employee " + param[1]));
//    EmplInfo.add_row({"ID", param[0]});
//    EmplInfo.add_row({"Name", param[1]});
//    EmplInfo.add_row({"Position", param[2]});
//    EmplInfo.add_row({"Salary", (param[3] == "") ? "N/A" : param[3]});

}

template <typename T>
void loadSCV(const std::string& directory, std::unordered_map<std::string, std::unique_ptr<Employee>>&STAFF_LIST, std::unordered_multimap<std::string, T*>&PROJECT_LIST) {
    std::ifstream file(directory);
    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        auto fields = split(line);
        if (fields.size() != 5) continue;

        if (fields[2] == "Cleaner") STAFF_LIST.insert({fields[0], std::make_unique<Cleaner>(fields[1], fields[2], fields[0], std::stoi(fields[3]))});
        else if (fields[2] == "Driver") STAFF_LIST.insert({fields[0], std::make_unique<Driver>(fields[1], fields[2], fields[0], std::stoi(fields[3]))});


    }
}

#endif //STAFFDEMO_FUNCTIONS_H
