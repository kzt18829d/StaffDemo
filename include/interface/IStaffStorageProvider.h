#ifndef STAFFDEMO_ISTAFFSTORAGEPROVIDER_H
#define STAFFDEMO_ISTAFFSTORAGEPROVIDER_H
#include <memory>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include "../staff/employee_temp.h"
#include "../staff/IEmployee.h"


namespace Interface {
    ///@brief Интерфейс для чтения/записи данных персонала
    ///@details
    ///@ingroup Interface
    class IStaffStorageProvider {
    public:
        virtual ~IStaffStorageProvider() = default;
        virtual std::queue<Staff::TempEmloyee> loadFromStorage() = 0;
        virtual std::map<std::string, std::shared_ptr<Staff::IEmployee>> saveToStorage() = 0;
    };
}

#endif //STAFFDEMO_ISTAFFSTORAGEPROVIDER_H
