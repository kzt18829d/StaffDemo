#ifndef STAFFDEMO_EMPLOYEE_TEMP_H
#define STAFFDEMO_EMPLOYEE_TEMP_H

#include <string>

namespace StaffDemo::Core::Staff {

    struct TempEmloyee {
        std::string id;
        std::string name;
        std::string position;
        std::string salary;
        std::string project;
        std::string nBonus;
        std::string PoB;
        std::string PADD;
        std::string tHeading;
    };

} // Core

#endif //STAFFDEMO_EMPLOYEE_TEMP_H
