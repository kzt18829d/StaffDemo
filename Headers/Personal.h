#ifndef STAFFDEMO_PERSONAL_H
#define STAFFDEMO_PERSONAL_H

#include "Employee.h"

class Personal : public Employee {
protected:
    float hourlyRate;
public:
    Personal();
    Personal(const std::string& name, float worktime, float hourlyRate);
    ~Personal() override;
    float getHourlyRate() const;
    void printInfo() const override;
};

class Cleaner : public Personal {
public:
    Cleaner();
    Cleaner(const std::string& name, float worktime, float hourlyRate);

    Cleaner(const std::string &name, float worktime, float hourlyRate);

    ~Cleaner() override;
    void calc() override;
    void printInfo() const override;
};

class Driver : public Personal {
private:
    float nightBonus;
public:
    Driver();
    Driver(std::string& name, float worktime, float hourlyRate, float nightBonus);
    ~Driver() override;
    float getNightBonus() const;
    void calc() override;
    void printInfo() const override;
};


#endif //STAFFDEMO_PERSONAL_H
