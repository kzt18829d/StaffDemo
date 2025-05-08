#include "Manager.h"

ProjectManager::ProjectManager(const std::string &name, const std::string &position, const std::string &id, int heading,
                               float partOfBudget, int proAddition, Project *project) :
        Employee(name, position, id), heading{heading}, partOfBudget{partOfBudget}, proAddition{proAddition}, project{project}
{}

int ProjectManager::calcBudgetPart(float part, int budget) {
    return static_cast<int>(part * budget / 100);
}

int ProjectManager::calcProAdditions() {
    return proAddition;
}

int ProjectManager::calcHeads() {
    return heading;
}

void ProjectManager::calc() {
    payment = calcBudgetPart(partOfBudget, project ? project->getBudget() : 0) + calcProAdditions() + calcHeads();
}

SeniorManager::SeniorManager(const std::string &name, const std::string &position, const std::string &id, int heading,
                             float partOfBudgets, int proAddition, const std::vector<Project *> &projects) :
        Employee(name, position, id), heading{heading}, partOfBudget{partOfBudgets}, proAddition{proAddition}, projects(projects)
{}

int SeniorManager::calcBudgetPart(float part, int budget) {
    return static_cast<int>(part * budget / 100);
}

int SeniorManager::calcProAdditions() {
    return proAddition;
}

int SeniorManager::calcHeads() {
    return heading;
}

void SeniorManager::calc() {
    payment = calcHeads() + calcProAdditions();
    for (const auto &project : projects) payment += calcBudgetPart(partOfBudget, project->getBudget());
}
