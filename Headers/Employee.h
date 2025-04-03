#ifndef STAFFDEMO_EMPLOYEE_H
#define STAFFDEMO_EMPLOYEE_H
#include <string>
#include <iostream>

class Employee {
protected:
    std::string id;
    std::string name;
    float worktime;
    float payment;
public:
    Employee();
    Employee(std::string& name, float worktime);
    virtual ~Employee();

    void setWorkTime();
    float getWorkTime() const;
    std::string getID() const;
    std::string getName() const;
    float getPayment() const;

    virtual void calc() = 0;
    virtual void printInfo() const = 0;
};


#endif //STAFFDEMO_EMPLOYEE_H
