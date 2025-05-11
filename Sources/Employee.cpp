#include <utility>
#include "Employee.h"


Employee::Employee(const std::string& name, const std::string& position, const std::string& id) :
    name{std::move(name)}, position{std::move(position)}, id{std::move(id)},
    worktime{0}, payment{0} {}

Employee::~Employee() = default;

void Employee::setWorkTime(int worktime_) {
    worktime = worktime_;
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

int Employee::getPayment() const {
    return payment;
}

bool Employee::operator==(const Employee &other) const {
    return this->id == other.id;
}

bool Employee::operator!=(const Employee &other) const {
    return this->id != other.id;
}
