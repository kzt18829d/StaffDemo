#ifndef STAFFDEMO_ISPSTORAGEPROVIDER_H
#define STAFFDEMO_ISPSTORAGEPROVIDER_H
#include <string>
#include <vector>
#include <queue>
#include <memory>
#include <map>
#include "../staff/Factory.h"
#include "../staff/employee_temp.h"
#include "../staff/IEmployee.h"


namespace Interface {
    ///@brief Интерфейс взаимодействия с данными персонала и проектов в файле
    ///@details Содержит чистые виртуальные методы для взаимодействия с файлами данных, содержащих информацию о персонале и проектах
    ///@ingroup Interface
    class ISPStorageProvider {
    public:
        virtual ~ISPStorageProvider() = default;
        virtual std::pair<std::queue<Staff::TempEmloyee>, std::vector<Staff::TempProject>> load() = 0;
        virtual void save(const std::vector<Staff::TempEmloyee>& staffs, const std::vector<Staff::TempProject>& projects) = 0;
        virtual void save(const std::map<std::string, std::weak_ptr<Staff::IEmployee>>& staffs, const std::map<std::string, std::weak_ptr<Staff::Project>>& projects) = 0;
    };
}

#endif //STAFFDEMO_ISPSTORAGEPROVIDER_H
