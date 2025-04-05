//
// Created by hid3h on 03.04.2025.
//

#include "../Headers/Manager.h"


ProjectManager::ProjectManager(const std::string &name, float worktime, Project *const project) :
    Employee(name, worktime), project{project} {}

ProjectManager::~ProjectManager() = default;

int ProjectManager::calcHeads(int heads) {
    return 0;
}

void ProjectManager::calc() {

}

