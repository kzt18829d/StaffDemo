#include <utility>
#include "Factory.h"

Project::Project(const std::string &name, int budget) :
    name{std::move(name)}, budget{budget}
{}

std::string Project::getName() const {
    return name;
}

int Project::getBudget() const {
    return budget;
}

