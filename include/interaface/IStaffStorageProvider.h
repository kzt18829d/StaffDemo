#ifndef STAFFDEMO_ISTAFFSTORAGEPROVIDER_H
#define STAFFDEMO_ISTAFFSTORAGEPROVIDER_H
#include <memory>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include "../staff/employee_temp.h"
#include "../staff/Employee.h"


namespace StaffDemo::Core::Interface {
    class IStaffStorageProvider {
    public:
        virtual ~IStaffStorageProvider() = default;
        virtual
        virtual std::queue<Staff::TempEmloyee> loadFromStorage() = 0;
        virtual std::map<std::string, std::shared_ptr<Staff::Employee>> saveToStorage() = 0;
    };
}

#endif //STAFFDEMO_ISTAFFSTORAGEPROVIDER_H
