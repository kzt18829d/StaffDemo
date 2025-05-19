#ifndef STAFFDEMO_FIELDSTRATEGY_H
#define STAFFDEMO_FIELDSTRATEGY_H
#include <string>
#include <memory>
#include "ftxui/component/component.hpp"

namespace StaffDemo::UI {

    struct FieldStrategy {
        std::unique_ptr<std::string> data;
        std::string placeholder;
        bool isNumericOnly;
        int maxLenght;
    };


} // UI
// StaffDemo

#endif //STAFFDEMO_FIELDSTRATEGY_H
