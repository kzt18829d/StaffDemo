#include <utility>
#include "Factory.h"
#include <algorithm>

Project::Project(std::string name, int budget) :
    name{std::move(name)}, budget{budget}
{}

std::string Project::getName() const {
    return name;
}

int Project::getBudget() const {
    return budget;
}

std::vector<std::weak_ptr<Employee>> Project::getMembers() {
    return members;
}

void Project::addMember(std::weak_ptr<Employee> member) {
    if (auto it = std::find_if(std::begin(this->members), std::end(this->members), [&](const std::weak_ptr<Employee>& currentMember) {
        return currentMember.lock() == member.lock();
    }); it != std::end(this->members)) throw staff::except::Duplicate();
    this->members.push_back(member);
}

void Project::removeMember(std::weak_ptr<Employee> member) {
    if (this->members.empty()) throw std::out_of_range("Project.Members empty.");
    if (auto it = std::find_if(std::begin(this->members), std::end(this->members), [&](const std::weak_ptr<Employee>& currentMember) {
            return currentMember.lock() == member.lock();
        }); it != std::end(this->members)) this->members.erase(it);
    else throw staff::except::notFind();
}

void Project::removeMember(const std::string& memberID) {
    if (this->members.empty()) throw std::out_of_range("Project.Members empty.");
    if (auto it = std::find_if(std::begin(this->members), std::end(this->members), [&](const std::weak_ptr<Employee> currentMember) {
            return currentMember.lock()->getID() == memberID;
        }); it != std::end(this->members)) this->members.erase(it);
    else throw staff::except::notFind();
}

void Project::removeMember() {
    if (this->members.empty()) throw std::out_of_range("Project.Members empty.");
    this->members.pop_back();
}

bool Project::operator==(const Project &other) const {
    return this->name == other.name;
}

bool Project::operator!=(const Project &other) const {
    return this->name != other.name;
}

bool Project::operator<(const Project &other) const {
    return this->budget < other.budget;
}

bool Project::operator>(const Project &other) const {
    return this->budget > other.budget;
}

bool Project::operator<=(const Project &other) const {
    return this->budget <= other.budget;
}

bool Project::operator>=(const Project &other) const  {
    return this->budget >= other.budget;
}
