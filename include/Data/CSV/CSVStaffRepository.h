#ifndef STAFFDEMO_STAFFREPOSITORYCSV_H
#define STAFFDEMO_STAFFREPOSITORYCSV_H

#include <map>
#include <memory>
#include "../../staff/IEmployee.h"
#include "../../utils/StaffExceptions.h"
#include <algorithm>

namespace Data::Repository {

    ///@brief Класс репозитория проектов
    ///@ingroup Data
    class CSVStaffRepository {
    private:
        std::map<std::string, std::shared_ptr<Staff::IEmployee>> STAFF_LIST{};
    public:
        void add(std::shared_ptr<Staff::IEmployee> staff);
        void remove(std::shared_ptr<Staff::IEmployee> staff);
        std::map<std::string, std::weak_ptr<Staff::IEmployee>> getAll() const;
        std::map<std::string, std::weak_ptr<Staff::IEmployee>> getByName(const std::string &name) const;
        std::map<std::string, std::weak_ptr<Staff::IEmployee>> getByPosition(const std::string &position) const;
        bool clean();
    };

} // StaffDemo

#endif //STAFFDEMO_STAFFREPOSITORYCSV_H
