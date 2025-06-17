#ifndef STAFFDEMO_SPLIT_H
#define STAFFDEMO_SPLIT_H
#include <vector>
#include <string>
#include <set>
#include <sstream>

namespace Utils {
    std::vector<std::string>split(const std::string& line, char delim=';');
    std::set<std::string>splitUnic(const std::string& line, char delim=':') noexcept;
}

#endif //STAFFDEMO_SPLIT_H
