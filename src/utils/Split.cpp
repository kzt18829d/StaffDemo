#include "../../include/utils/Split.h"

namespace StaffDemo::Utils {
    std::vector<std::string> split(const std::string &line, char delim) {
        std::vector<std::string> result;
        std::stringstream ss(line);
        std::string value;

        while (std::getline(ss, value, delim)) result.push_back(value);
        return result;
    }

    std::set<std::string> splitUnic(const std::string &line, char delim) noexcept {
        std::set<std::string> split;
        std::stringstream ss(line);
        std::string value;
        try {
            while (std::getline(ss, value, delim)) split.insert(value);
        } catch (...) {}
        return split;
    }
}