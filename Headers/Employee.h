#ifndef STAFFDEMO_EMPLOYEE_H
#define STAFFDEMO_EMPLOYEE_H
#include <string>
#include <iostream>

struct TempEmloyee {
    std::string id;
    std::string name;
    std::string position;
    std::string salary;
    std::string project;
    std::string nBonus;
    std::string PoB;
    std::string PADD;
    std::string tHeading;
};


///@Positions (pos[posInFile]):
///@Cleaner[cleaner] @tDriver[driver]
///@Programmer[programmer] @Tester[tester] @TeamLeader[timlid]
///@ProjectManager[projectm] @SeniorManager[seniorm]
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

    bool operator==(const Employee& other) const;
    bool operator!=(const Employee& other) const;
};

#endif //STAFFDEMO_EMPLOYEE_H
