#ifndef STAFFDEMO_STAFFREPOSITORYCSV_H
#define STAFFDEMO_STAFFREPOSITORYCSV_H

#include "../../interaface/IStaffRepository.h"
#include "../../interaface/IStaffStorageProvider.h"
#include <map>
#include <memory>
#include "../../staff/IEmployee.h"
#include "../../utils/StaffExceptions.h"
#include <algorithm>

namespace Data::Repository {

    ///@brief Класс репозитория проектов
    ///@ingroup Data
    class CSVStaffRepository : public Interface::IStaffRepository {
    private:
        std::map<std::string, std::shared_ptr<Staff::IEmployee>> STAFF_LIST;
    public:
        void add(std::shared_ptr<Staff::IEmployee> staff) override;
        void remove(std::shared_ptr<Staff::IEmployee> staff) override;
        std::map<std::string, std::weak_ptr<Staff::IEmployee>> getAll() const override;
        std::map<std::string, std::weak_ptr<Staff::IEmployee>> getByName(const std::string &name) const override;
        std::map<std::string, std::weak_ptr<Staff::IEmployee>> getByPosition(const std::string &position) const override;
    };

} // StaffDemo

#endif //STAFFDEMO_STAFFREPOSITORYCSV_H
