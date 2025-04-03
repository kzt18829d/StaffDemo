#ifndef STAFFDEMO_MANAGER_H
#define STAFFDEMO_MANAGER_H
#include "Employee.h"
#include "Interfaces.h"
#include "Factory.h"
#include <string>

class ProjectManager : public Employee, public Project, public Heading {
private:
    Project* project[1];
public:
    ProjectManager(const std::string& name, float worktime, Project* project);
    ~ProjectManager() override;
    int calcHeads(int heads) override;
    void calc() override;
};

class SeniorManager : public ProjectManager {
private:
    std::vector<Project*> project;
public:
    SeniorManager(const std::string &name1, float worktime1, Project *project1, const std::string &name,
                  float worktime, const std::vector<Project *>& project);
    ~SeniorManager() override;
    void calc() override;
};


#endif //STAFFDEMO_MANAGER_H
