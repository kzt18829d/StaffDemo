//
// Created by hid3h on 03.04.2025.
//

#include <utility>

#include "../Headers/Factory.h"
#include "../CustomLib/Generators.h"

Project::Project() : Project(genid(10, false), 0) {}

Project::Project(std::string projectName, float budget) : projectName{std::move(projectName)}, budget{budget} {}

Project::~Project() = default;
