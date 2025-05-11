#ifndef STAFFDEMO_PERSONAL_H
#define STAFFDEMO_PERSONAL_H

#include "Employee.h"
#include "Interfaces.h"

class Personal : public Employee, public WorkBaseTime {
protected:
    int salary;
public:
    Personal(const std::string& name, const std::string& position, const std::string& id, int salary);
    virtual ~Personal() override = default;

    int calcBase(int salary_, int worktime_) override;
    int calcBonus() override;

    int getSalary() const;

    void calc() override;
};

class Cleaner : public Personal {
public:
    Cleaner(const std::string& name, const std::string& position, const std::string& id, int salary);
    ~Cleaner() override = default;
};

class Driver : public Personal {
private:
    int nightBonus;
public:
    Driver(const std::string& name, const std::string& position, const std::string& id, int salary, int nBonus);
    ~Driver() override = default;
    int calcBonus() override;
};

#endif //STAFFDEMO_PERSONAL_H
