#include "../../include/data/CSV/CSVProjectRepository.h"
#include <exception>
namespace Data::Repository {
    void CSVProjectRepository::add(std::shared_ptr<Staff::Project> project) {
        if (PROJECT_LIST.contains(project->getName())) {
            // <-log
//            throw Utils::except::previouslyAdded("Project " + project->getName() + " was previously added.");
        }
        PROJECT_LIST[project->getName()] = project;
    }

    void CSVProjectRepository::remove(std::shared_ptr<Staff::Project> project) {
        if (auto it = std::find_if(std::begin(PROJECT_LIST), std::end(PROJECT_LIST), [&](const auto& currProject ){
                return currProject.first == project->getName();
            }); it != std::end(PROJECT_LIST)) PROJECT_LIST.erase(it);
    }

    std::map<std::string, std::weak_ptr<Staff::Project>> CSVProjectRepository::getProjects() const {
        std::map<std::string, std::weak_ptr<Staff::Project>> temp;
        std::for_each(PROJECT_LIST.begin(), PROJECT_LIST.end(), [&](const auto& line){
            temp[line.first] = line.second;
        });
        return temp;
    }

    std::vector<std::weak_ptr<Staff::IEmployee>> CSVProjectRepository::getStaff(std::shared_ptr<Staff::Project> project) const {
        if (auto it = std::find_if(std::begin(PROJECT_LIST), std::end(PROJECT_LIST), [&](const auto& findProject) {
                return findProject.first == project->getName();
            }); it != std::end(PROJECT_LIST)) return it->second->getMembers();
        else {
            // <- log
            throw std::out_of_range("Not find");
        }
    }

    std::vector<std::weak_ptr<Staff::IEmployee>> CSVProjectRepository::getStaff(const std::string &projectName) const {
        if (auto it = std::find_if(std::begin(PROJECT_LIST), std::end(PROJECT_LIST), [&](const auto& currProject) {
                return currProject.first == projectName;
            }); it != std::end(PROJECT_LIST)) return it->second->getMembers();
        else {
            // <- log
            throw std::out_of_range("not find");
        }
    }

    void CSVProjectRepository::addStaff(std::shared_ptr<Staff::IEmployee> staff, std::shared_ptr<Staff::Project> project) {
        if (auto it = std::find_if(std::begin(PROJECT_LIST), std::end(PROJECT_LIST), [&](const auto& currProject) {
                return currProject.first == project->getName();
            }); it != std::end(PROJECT_LIST)) it->second->addMember(staff);
        else {
            // <- log
            throw std::out_of_range("not find");
        }
    }

    void CSVProjectRepository::addStaff(std::shared_ptr<Staff::IEmployee> staff, const std::string &project) {
        if (auto it = std::find_if(std::begin(PROJECT_LIST), std::end(PROJECT_LIST), [&](const auto& currProject) {
                return currProject.first == project;
            }); it != std::end(PROJECT_LIST)) it->second->addMember(staff);
        else {
            // <- log
            throw std::out_of_range("not find");
        }
    }

    void CSVProjectRepository::removeStaff(std::shared_ptr<Staff::IEmployee> staff, std::shared_ptr<Staff::Project> project) {
        if (auto it = std::find_if(std::begin(PROJECT_LIST), std::end(PROJECT_LIST), [&](const auto& currProject) {
                return currProject.first == project->getName();
            }); it != std::end(PROJECT_LIST)) it->second->removeMember(staff);
        else {
            // <- log
            throw std::out_of_range("not find");
        }
    }

    void CSVProjectRepository::removeStaff(std::shared_ptr<Staff::IEmployee> staff, const std::string &project) {
        if (auto it = std::find_if(std::begin(PROJECT_LIST), std::end(PROJECT_LIST), [&](const auto& currProject) {
                return currProject.first == project;
            }); it != std::end(PROJECT_LIST)) it->second->removeMember(staff);
        else {
            // <- log
            throw std::out_of_range("not find");
        }
    }

    void CSVProjectRepository::relocateStaff(std::shared_ptr<Staff::IEmployee> staff, std::shared_ptr<Staff::Project> fromProject, std::shared_ptr<Staff::Project> toProject) {
        auto it1 = std::find_if(std::begin(PROJECT_LIST), std::end(PROJECT_LIST), [&](const auto& currProject ){
            return currProject.first == fromProject->getName();});
        auto it2 = std::find_if(std::begin(PROJECT_LIST), std::end(PROJECT_LIST), [&](const auto& currProject ){
            return currProject.first == toProject->getName();});
        if (it1->first == it2->first || it1 == PROJECT_LIST.end() || it2 == PROJECT_LIST.end()) {
            // <- log
            throw std::runtime_error("Ошибка проекта");
        }
        try {
            removeStaff(staff, fromProject);
            addStaff(staff, toProject);
        } catch (const std::exception& exception) {
            throw exception.what();
        }
    }

    void CSVProjectRepository::relocateStaff(std::shared_ptr<Staff::IEmployee> staff, std::shared_ptr<Staff::Project> fromProject, const std::string &toProject) {
        auto it1 = std::find_if(std::begin(PROJECT_LIST), std::end(PROJECT_LIST), [&](const auto& currProject ){
            return currProject.first == fromProject->getName();});
        auto it2 = std::find_if(std::begin(PROJECT_LIST), std::end(PROJECT_LIST), [&](const auto& currProject ){
            return currProject.first == toProject;});
        if (it1->first == it2->first || it1 == PROJECT_LIST.end() || it2 == PROJECT_LIST.end()) {
            // <- log
            throw std::runtime_error("Ошибка проекта");
        }
        try {
            removeStaff(staff, fromProject);
            addStaff(staff, toProject);
        } catch (const std::exception& exception) {
            throw exception.what();
        }
    }

    void CSVProjectRepository::relocateStaff(std::shared_ptr<Staff::IEmployee> staff, const std::string &fromProject, std::shared_ptr<Staff::Project> toProject) {
        auto it1 = std::find_if(std::begin(PROJECT_LIST), std::end(PROJECT_LIST), [&](const auto& currProject ){
            return currProject.first == fromProject; });
        auto it2 = std::find_if(std::begin(PROJECT_LIST), std::end(PROJECT_LIST), [&](const auto& currProject ){
            return currProject.first == toProject->getName();});
        if (it1->first == it2->first || it1 == PROJECT_LIST.end() || it2 == PROJECT_LIST.end()) {
            // <- log
            throw std::runtime_error("Ошибка проекта");
        }
        try {
            removeStaff(staff, fromProject);
            addStaff(staff, toProject);
        } catch (const std::exception& exception) {
            throw exception.what();
        }
    }

    void CSVProjectRepository::relocateStaff(std::shared_ptr<Staff::IEmployee> staff,
                                                                                 const std::string &fromProject, const std::string &toProject) {
        auto it1 = std::find_if(std::begin(PROJECT_LIST), std::end(PROJECT_LIST), [&](const auto& currProject ){
            return currProject.first == fromProject;});
        auto it2 = std::find_if(std::begin(PROJECT_LIST), std::end(PROJECT_LIST), [&](const auto& currProject ){
            return currProject.first == toProject;});
        if (it1->first == it2->first || it1 == PROJECT_LIST.end() || it2 == PROJECT_LIST.end()) {
            // <- log
            throw std::runtime_error("Ошибка проекта");
        }
        try {
            removeStaff(staff, fromProject);
            addStaff(staff, toProject);
        } catch (const std::exception& exception) {
            throw exception.what();
        }
    }

    bool CSVProjectRepository::clean() {
        try{
            PROJECT_LIST.clear();
        } catch (...) { return false; }
        if (!PROJECT_LIST.empty()) return false;
        return true;
    }
}

