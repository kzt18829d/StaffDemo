//
// Created by hid3h on 03.04.2025.
//

#include <utility>

#include "../Headers/Factory.h"
#include "../CustomLib/Functions.h"
#include <iostream>
#include <iomanip>

Project::Project(const std::string &name, int budget) :
    name{std::move(name)}, budget{budget}
{}

std::string Project::getName() const {
    return name;
}

int Project::getBudget() const {
    return budget;
}

