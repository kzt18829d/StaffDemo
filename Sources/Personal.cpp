#include "Personal.h"

Personal::Personal(const std::string &name, const std::string &position, const std::string &id, int salary) :
    Employee(name, position, id), salary{salary} {}

int Personal::calcBase(int salary_, int worktime_) {
    return salary_ * worktime_;
}

int Personal::calcBonus() {
    return 0;
}

void Personal::calc() {
    payment = calcBase(salary, worktime) + calcBonus();
}

int Personal::getSalary() const {
    return salary;
}

Cleaner::Cleaner(const std::string &name, const std::string &position, const std::string &id, int salary) :
    Personal(name, position, id, salary) {}

Driver::Driver(const std::string &name, const std::string &position, const std::string &id, int salary, int nBonus) :
        Personal(name, position, id, salary), nightBonus{nBonus} {}

int Driver::calcBonus() {
    return nightBonus;
}
