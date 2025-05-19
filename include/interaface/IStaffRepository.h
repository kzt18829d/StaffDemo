#ifndef STAFFDEMO_IUSERREPOSITORY_H
#define STAFFDEMO_IUSERREPOSITORY_H
#include <memory>
#include <map>
#include "staff/Employee.h"

namespace StaffDemo::Core::Interface {
    class IStaffRepository {
    public:
        virtual ~IStaffRepository() = default;
        virtual void add(std::shared_ptr<StaffDemo::Core::Staff::Employee> staff) = 0;
        virtual void remove(std::shared_ptr<StaffDemo::Core::Staff::Employee> staff) = 0;
        virtual std::map<std::string, std::weak_ptr<StaffDemo::Core::Staff::Employee>> getAll() const = 0;
        virtual std::map<std::string, std::weak_ptr<StaffDemo::Core::Staff::Employee>> getByName(const std::string& name) const = 0;
        virtual std::map<std::string, std::weak_ptr<StaffDemo::Core::Staff::Employee>> getByPosition(const std::string& position) const = 0;
        virtual void update(std::shared_ptr<StaffDemo::Core::Staff::Employee> staff) = 0;
    };
}


#endif //STAFFDEMO_IUSERREPOSITORY_H
