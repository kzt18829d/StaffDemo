#include <utility>
#include "../../include/staff/IEmployee.h"
namespace StaffDemo::Staff {
    IEmployee::IEmployee(const std::string &name, const std::string &position,
                         const std::string &id) : worktime{0}, payment{0} {}

    int IEmployee::getPayment() const {
        return payment;
    }

    bool IEmployee::operator==(const IEmployee &other) const {
        return this->id == other.id;
    }

    bool IEmployee::operator!=(const IEmployee &other) const {
        return this->id != other.id;
    }

    IEmployee::~IEmployee() = default;

    void IEmployee::setWorkTime(int worktime_) {

    }

    std::string IEmployee::getID() const {
        return id;
    }

    std::string IEmployee::getName() const {
        return name;
    }

    std::string IEmployee::getPosition() const {
        return position;
    }

    int IEmployee::getWorkTime() const {
        return worktime;
    }
}

