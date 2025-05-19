#ifndef STAFFDEMO_CSVPROJECTREPOSITORY_H
#define STAFFDEMO_CSVPROJECTREPOSITORY_H

#include "interaface/IProjectRepository.h"
#include "../staff/Employee.h"
#include "../staff/Factory.h"
#include "../utils/StaffExceptions.h"
#include <map>
#include <string>
#include <memory>
#include <algorithm>

namespace StaffDemo::Core::ProjectRepository {
    class CSVProjectRepository : public Interface::IProjectRepository {
    private:
        std::map<std::string, std::shared_ptr<Staff::Project>> PROJECT_LIST;

    public:
        void add(std::shared_ptr<Staff::Project> project) override;
        void remove(std::shared_ptr<Staff::Project> project) override;

        std::map<std::string, std::shared_ptr<Staff::Project>> getProjects() const override;
        std::vector<std::weak_ptr<Staff::Employee>> getStaff(std::shared_ptr<Staff::Project> project) const override;
        std::vector<std::weak_ptr<Staff::Employee>> getStaff(const std::string &projectName) const override;

        void addStaff(std::shared_ptr<Staff::Employee> staff, std::shared_ptr<Staff::Project> project) override;
        void addStaff(std::shared_ptr<Staff::Employee> staff, const std::string &project) override;
        void removeStaff(std::shared_ptr<Staff::Employee> staff, std::shared_ptr<Staff::Project> project) override;
        void removeStaff(std::shared_ptr<Staff::Employee> staff, const std::string &project) override;

        void relocateStaff(std::shared_ptr<Staff::Employee> staff, std::shared_ptr<Staff::Project> fromProject, std::shared_ptr<Staff::Project> toProject) override;
        void relocateStaff(std::shared_ptr<Staff::Employee> staff, std::shared_ptr<Staff::Project> fromProject, const std::string &toProject) override;
        void relocateStaff(std::shared_ptr<Staff::Employee> staff, const std::string &fromProject, std::shared_ptr<Staff::Project> toProject) override;
        void relocateStaff(std::shared_ptr<Staff::Employee> staff, const std::string &fromProject, const std::string &toProject) override;
    };

}


#endif //STAFFDEMO_CSVPROJECTREPOSITORY_H
