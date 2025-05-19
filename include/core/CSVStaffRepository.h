#ifndef STAFFDEMO_STAFFREPOSITORYCSV_H
#define STAFFDEMO_STAFFREPOSITORYCSV_H

#include "interaface/IStaffRepository.h"
#include "interaface/IStaffStorageProvider.h"
#include <map>
#include <memory>
#include "staff/Employee.h"
#include "utils/StaffExceptions.h"
#include "utils/Logger.h"
#include <algorithm>

namespace StaffDemo::Core::StaffRepository {

    class CSVStaffRepository : Interface::IStaffRepository {
    private:
        std::map<std::string, std::shared_ptr<Staff::Employee>> STAFF_LIST;
    public:
        void add(std::shared_ptr<StaffDemo::Core::Staff::Employee> staff) override;
        void remove(std::shared_ptr<StaffDemo::Core::Staff::Employee> staff) override;
        std::map<std::string, std::weak_ptr<StaffDemo::Core::Staff::Employee>> getAll() const override;
        std::map<std::string, std::weak_ptr<StaffDemo::Core::Staff::Employee>> getByName(const std::string &name) const override;
        std::map<std::string, std::weak_ptr<StaffDemo::Core::Staff::Employee>> getByPosition(const std::string &position) const override;
    };

} // StaffDemo

#endif //STAFFDEMO_STAFFREPOSITORYCSV_H
