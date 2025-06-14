//
// Created by hid3h on 12.06.2025.
//

#ifndef STAFFDEMO_INFOTYPEENUM_H
#define STAFFDEMO_INFOTYPEENUM_H
#include "string"
namespace Core {
    enum class InfoType {
        INFO,
        WARNING,
        ERROR,
        FATAL_ERROR
    };

    std::string getInfoTypeByText(InfoType infoType) {
        switch (infoType) {
            case InfoType::INFO:        return std::string("[INFO]");
            case InfoType::WARNING:     return std::string("[WARN]");
            case InfoType::ERROR:       return std::string("[ERROR]");
            case InfoType::FATAL_ERROR: return std::string("[FATAL_ERROR]");
        }
        return "";
    }
}


#endif //STAFFDEMO_INFOTYPEENUM_H
