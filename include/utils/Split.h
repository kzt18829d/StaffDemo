#ifndef STAFFDEMO_SPLIT_H
#define STAFFDEMO_SPLIT_H
#include <vector>
#include <string>
#include <set>
#include <sstream>

namespace Utils {
    inline std::vector<std::string>split(const std::string& line, char delim=';');
    inline std::set<std::string>splitUnic(const std::string& line, char delim=':') noexcept;
}

#endif //STAFFDEMO_SPLIT_H
