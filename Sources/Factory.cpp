//
// Created by hid3h on 03.04.2025.
//

#include <utility>

#include "../Headers/Factory.h"
#include "../CustomLib/Generators.h"
#include <iostream>
#include <iomanip>

Project::Project() : Project(genid(10, false), 0) {}

Project::Project(std::string projectName, float budget) : projectName{std::move(projectName)}, budget{budget} {}

Project::~Project() = default;


std::string Project::getProjectName() const { return projectName; }

float Project::getBudget() const { return budget; }

void Project::showProjectInfo() const {
    std::cout << std::setw(30) << std::setfill('-') << " Project Info " << std::setw(16) << "" << std::endl;
    std::cout << std::setfill(' ');
    std::cout << std::left << std::setw(30) << "Project name: " << std::setw(16) << getProjectName() << std::endl <<
                std::setw(30) << " Project Budget " << std::setw(16) << getBudget() << std::endl;
    std::cout << std::setw(46) << std::setfill('-') << "" << std::endl << std::setfill(' ');
}

