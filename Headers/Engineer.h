#ifndef STAFFDEMO_ENGINEER_H
#define STAFFDEMO_ENGINEER_H
#include <string>
#include "Personal.h"
#include "Factory.h"
#include "Interfaces.h"

class Engineer : public Personal, public Project, public ProjectBudget{
protected:
    Project project;
    float bonusForProject;
public:
    Engineer(const std::string& name, float worktime, float hourlyRate, const Project& project);
    ~Engineer() override;
    int calcBudgetPart(float part, int budget) override;
    void calc() override;
};

class Tester : public Engineer {
public:
    Tester(const std::string& name, float worktime, float hourlyRate, const Project& project);
    ~Tester() override;
    int calcProAdditions() override;
};

class Programmer : public Engineer {
protected:
    int premier;
public:
    Programmer(const std::string& name, float worktime, float hourlyRate, const Project& project);
    ~Programmer() override;
    int calcProAdditions() override;
};

class TeamLeader : public Programmer, public Heading {
public:
    TeamLeader(const std::string& name, float worktime, float hourlyRate, const Project& project);
    ~TeamLeader() override;
    int calcHeads(int heads) override;
    void calc() override;
};


#endif //STAFFDEMO_ENGINEER_H
