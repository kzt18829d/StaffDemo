#ifndef STAFFDEMO_MANAGER_H
#define STAFFDEMO_MANAGER_H
#include "Employee.h"
#include "Interfaces.h"
#include "Factory.h"
#include <string>
#include <vector>

class ProjectManager : public Employee, public ProjectBudget, public Heading {
private:
    Project* project;
protected:
    float partOfBudget;
    int heading;
    int proAddition;
public:
    ProjectManager(const std::string& name, const std::string& position, const std::string& id, int heading, float partOfBudget, int proAddition, Project* project);
    ~ProjectManager() override = default;

    int calcBudgetPart(float part, int budget) override;
    int calcProAdditions() override;
    int calcHeads() override;

    void calc() override;
};

class SeniorManager : public Employee, public ProjectBudget, public Heading {
private:
    std::vector<Project*> projects;
    float partOfBudget;
    int heading;
    int proAddition;
public:
    SeniorManager(const std::string& name, const std::string& position, const std::string& id, int heading, float partOfBudgets, int proAddition, const std::vector<Project*>& projects);
    ~SeniorManager() override = default;

    int calcBudgetPart(float part, int budget) override;
    int calcProAdditions() override;
    int calcHeads() override;

    void calc() override;
};

#endif //STAFFDEMO_MANAGER_H
