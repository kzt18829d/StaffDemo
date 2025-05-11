#include "Manager.h"

#include <utility>

ProjectManager::ProjectManager(const std::string &name, const std::string &position, const std::string &id, int heading,
                               float partOfBudget, int proAddition, std::shared_ptr<Project>project) :
        Employee(name, position, id), heading{heading}, partOfBudget{partOfBudget}, proAddition{proAddition}, project{project}
{}

int ProjectManager::calcBudgetPart(float part, int budget) {
    return static_cast<int>(part * static_cast<float>(budget) / 100);
}

int ProjectManager::calcProAdditions() {
    return proAddition;
}

int ProjectManager::calcHeads() {
    return heading;
}

void ProjectManager::calc() {
    int PoB{0};
    if (auto proj = project.lock()) {
        PoB = proj->getBudget();
    }
    payment = calcBudgetPart(partOfBudget, PoB) + calcProAdditions() + calcHeads();
}

std::weak_ptr<Project> ProjectManager::getProject() {
    return project;
}

SeniorManager::SeniorManager(const std::string &name, const std::string &position, const std::string &id, int heading,
                             float partOfBudgets, int proAddition, std::map<std::string, std::weak_ptr<Project>> projectsMap) :
        Employee(name, position, id), heading{heading}, partOfBudget{partOfBudgets}, proAddition{proAddition}, projects{std::move(projectsMap)}
{}

int SeniorManager::calcBudgetPart(float part, int budget) {
    return static_cast<int>(part * static_cast<float>(budget) / 100);
}

int SeniorManager::calcProAdditions() {
    return proAddition;
}

int SeniorManager::calcHeads() {
    return heading;
}

void SeniorManager::calc() {

    payment = calcHeads() + calcProAdditions();
    for (const auto& [projectName, project] : projects) {
        int PoB{0};
        if (auto project_lock = project.lock()) PoB += project_lock->getBudget();
        payment += calcBudgetPart(partOfBudget, PoB);
    }
}

std::map<std::string, std::weak_ptr<Project>> SeniorManager::getProjects() {
    return projects;
}

std::vector<std::string> SeniorManager::getProjectsNames() {
    std::vector<std::string> projectNames;
    for (const auto& [projectName, project] : projects) projectNames.push_back(projectName);
    return projectNames;
}

void SeniorManager::addProject(std::weak_ptr<Project> project) {
    // a la security :)
    if (auto project_lock = project.lock()) this->projects[project_lock->getName()] = std::move(project);
}

void SeniorManager::removeProject(std::weak_ptr<Project> project) {
    if (auto project_lock = project.lock()) this->projects.erase(project_lock->getName());
}

//void SeniorManager::removeProject(const std::string &projectName_) {
//    if (auto it = std::find_if(std::begin(this->projects), std::end(this->projects), [&](
//                const std::pair<const std::basic_string<char>, std::weak_ptr<Project>>& currentProject) {
//        return currentProject.second.lock()->getName() == projectName_;
//    }); it != this->projects.end()) this->projects.erase(it);
//}
