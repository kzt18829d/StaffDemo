#include "Engineer.h"

Engineer::Engineer(const std::string &name, const std::string &position, const std::string &id, int salary,
       Project *project, float partOfBudget) :
       Personal(name, position, id, salary), project{project}, partOfBudget(partOfBudget)
{}

int Engineer::calcBudgetPart(float part, int budget) {
    return static_cast<int>(part * budget / 100);
}

int Engineer::calcProAdditions() {
    return 0;
}

void Engineer::calc() {
    payment = Personal::calcBase(salary, worktime) + calcBudgetPart(partOfBudget, project ? project->getBudget() : 0) + calcProAdditions();
}

Programmer::Programmer(const std::string &name, const std::string &position, const std::string &id, int salary,
                       Project *project, int proAdditions, float partOfBudget) :
        Engineer(name, position, id,salary, project, partOfBudget), proAdditions{proAdditions}
{}

void Programmer::addProAdditions(int add) {
    proAdditions += add;
}

void Programmer::removeProAdditiond(int remove) {
    if (remove > proAdditions) throw std::overflow_error(std::string("Rem.value > proAddition"));
    proAdditions -= remove;
}

int Programmer::calcProAdditions() {
    return proAdditions;
}

Tester::Tester(const std::string &name, const std::string &position, const std::string &id, int salary,
               Project *project, int proAdditions, float partOfBudget) :
        Engineer(name, position, id, salary, project, partOfBudget), proAdditions{proAdditions}
{}

void Tester::addProAdditions(int add) {
    proAdditions += add;
}

void Tester::removeProAdditiond(int remove) {
    if (remove > proAdditions) throw std::overflow_error(std::string("Rem.value > proAddition"));
    proAdditions -= remove;
}

int Tester::calcProAdditions() {
    return proAdditions;
}

TeamLeader::TeamLeader(const std::string &name, const std::string &position, const std::string &id, int salary,
                       Project *project, int proAdditions, float partOfBudget, int teamHeading) :
        Programmer(name, position, id, salary, project, proAdditions, partOfBudget), teamHeading(teamHeading)
{}

int TeamLeader::calcHeads() {
    return teamHeading;
}

void TeamLeader::calc() {
    payment = Personal::calcBase(salary, worktime) + Engineer::calcBudgetPart(partOfBudget, project ? project->getBudget() : 0) + Programmer::calcProAdditions() + calcHeads();
}
