#include <utility>
#include <algorithm>

#include "../../include/staff/Factory.h"

using namespace StaffDemo::Utils;

namespace StaffDemo::Core::Staff {
    Project::Project(std::string name, int budget) :
            name{std::move(name)}, budget{budget} {
        FileLogger::instance().log("Created project " + this->name + ".");
        FileLogger::instance().flush();
    }

    std::string Project::getName() const {
        FileLogger::instance().log("Project " + this->name + " call Project::getName().");
        FileLogger::instance().flush();
        return name;
    }

    int Project::getBudget() const {
        FileLogger::instance().log("Project " + this->name + " call Project::getBudget().");
        FileLogger::instance().flush();
        return budget;
    }

    std::vector<std::weak_ptr<Employee>> Project::getMembers() {
        FileLogger::instance().log("Project " + this->name + " call Project::getMembers().");
        FileLogger::instance().flush();
        return members;
    }

    void Project::addMember(std::weak_ptr<Employee> member) {
        FileLogger::instance().log("Project " + this->name + " call Project::addMember().");
        if (auto it = std::find_if(std::begin(this->members), std::end(this->members), [&](const std::weak_ptr<StaffDemo::Core::Employees::Employee>& currentMember) {
                return currentMember.lock() == member.lock();
            }); it != std::end(this->members)) {
            FileLogger::instance().log("Project " + this->name + " attempt add Duplicate.", StaffDemo::Utils::FileLogger::instance()::FileLogger::instance()::WARNING);
            FileLogger::instance().flush();
            throw StaffDemo::Utils::except::Duplicate();
        }
        this->members.push_back(member);
        FileLogger::instance().flush();
    }

    void Project::removeMember(std::weak_ptr<Employee> member) {
        FileLogger::instance().log("Project " + this->name + " call Project::removeMember().");
        if (this->members.empty()) {
            FileLogger::instance().log("Project " + this->name + " -> member list EMPTY.");
            FileLogger::instance().flush();
            throw std::out_of_range("Project.Members empty.");
        }
        if (auto it = std::find_if(std::begin(this->members), std::end(this->members), [&](const std::weak_ptr<StaffDemo::Core::Employees::Employee>& currentMember) {
                return currentMember.lock() == member.lock();
            }); it != std::end(this->members)) this->members.erase(it);
        else throw StaffDemo::Utils::except::notFind();
    }

    void Project::removeMember(const std::string& memberID) {
        if (this->members.empty()) throw std::out_of_range("Project.Members empty.");
        if (auto it = std::find_if(std::begin(this->members), std::end(this->members), [&](const std::weak_ptr<StaffDemo::Core::Employees::Employee> currentMember) {
                return currentMember.lock()->getID() == memberID;
            }); it != std::end(this->members)) this->members.erase(it);
        else throw StaffDemo::Utils::except::notFind();
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

}
