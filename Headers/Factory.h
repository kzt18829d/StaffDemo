#ifndef STAFFDEMO_FACTORY_H
#define STAFFDEMO_FACTORY_H
#include <string>
#include <vector>
#include <set>
#include <memory>
#include "Employee.h"
#include "StaffExceptions.h"

class Project {
private:
    std::string name;
    int budget;
    std::vector<std::weak_ptr<Employee>> members;
public:
    explicit Project(std::string  name, int budget=0);

    std::string getName() const;
    int getBudget() const;

    std::vector<std::weak_ptr<Employee>> getMembers();

    void addMember(std::weak_ptr<Employee> member);
    ///Remove to ptr
    void removeMember(std::weak_ptr<Employee> member);
    ///Remover to employee id
    void removeMember(const std::string& memberID);
    ///Remove last
    void removeMember();

    bool operator==(const Project& other) const;
    bool operator!=(const Project& other) const;
    bool operator<(const Project& other) const;
    bool operator>(const Project& other) const;
    bool operator<=(const Project& other) const;
    bool operator>=(const Project& other) const;

};

#endif //STAFFDEMO_FACTORY_H
