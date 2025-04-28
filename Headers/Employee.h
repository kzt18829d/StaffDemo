#ifndef STAFFDEMO_EMPLOYEE_H
#define STAFFDEMO_EMPLOYEE_H
#include <string>
#include <iostream>

class Employee {
protected:
    std::string id;
    std::string name;
    std::string position;
    int worktime;
    int payment;
public:
    Employee(const std::string& name, const std::string& position, const std::string& id);
    virtual ~Employee();

    void setWorkTime(int worktime_);
    virtual void calc() = 0;

    std::string getID() const;
    std::string getName() const;
    std::string getPosition() const;
    int getWorkTime() const;
    int getPayment() const;
};


#endif //STAFFDEMO_EMPLOYEE_H
