#include <utility>
#include "../../include/staff/Employee.h"
namespace StaffDemo::Core::Staff {
    Employee::Employee(const std::string &name, const std::string &position,
                                                   const std::string &id) : worktime{0}, payment{0} {}

    int Employee::getPayment() const {
        return payment;
    }

    bool Employee::operator==(const Employee &other) const {
        return this->id == other.id;
    }

    bool Employee::operator!=(const Employee &other) const {
        return this->id != other.id;
    }

    Employee::~Employee() = default;

    void Employee::setWorkTime(int worktime_) {

    }

    std::string Employee::getID() const {
        return id;
    }

    std::string Employee::getName() const {
        return name;
    }

    std::string Employee::getPosition() const {
        return position;
    }

    int Employee::getWorkTime() const {
        return worktime;
    }
}

