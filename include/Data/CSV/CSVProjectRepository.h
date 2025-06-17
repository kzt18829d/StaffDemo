#ifndef STAFFDEMO_CSVPROJECTREPOSITORY_H
#define STAFFDEMO_CSVPROJECTREPOSITORY_H

#include "../../staff/IEmployee.h"
#include "../../staff/Factory.h"
#include "../../utils/StaffExceptions.h"
#include <map>
#include <string>
#include <memory>
#include <algorithm>

namespace Data::Repository {
    ///@brief Класс репозитория проектов
    ///@ingroup Data
    class CSVProjectRepository {
    private:
        std::map<std::string, std::shared_ptr<Staff::Project>> PROJECT_LIST{};

    public:
        void add(std::shared_ptr<Staff::Project> project);
        void remove(std::shared_ptr<Staff::Project> project);

        std::map<std::string, std::weak_ptr<Staff::Project>> getProjects() const;
        std::vector<std::weak_ptr<Staff::IEmployee>> getStaff(std::shared_ptr<Staff::Project> project) const;
        std::vector<std::weak_ptr<Staff::IEmployee>> getStaff(const std::string &projectName) const;

        void addStaff(std::shared_ptr<Staff::IEmployee> staff, std::shared_ptr<Staff::Project> project);
        void addStaff(std::shared_ptr<Staff::IEmployee> staff, const std::string &project);
        void removeStaff(std::shared_ptr<Staff::IEmployee> staff, std::shared_ptr<Staff::Project> project);
        void removeStaff(std::shared_ptr<Staff::IEmployee> staff, const std::string &project);

        void relocateStaff(std::shared_ptr<Staff::IEmployee> staff, std::shared_ptr<Staff::Project> fromProject, std::shared_ptr<Staff::Project> toProject);
        void relocateStaff(std::shared_ptr<Staff::IEmployee> staff, std::shared_ptr<Staff::Project> fromProject, const std::string &toProject);
        void relocateStaff(std::shared_ptr<Staff::IEmployee> staff, const std::string &fromProject, std::shared_ptr<Staff::Project> toProject);
        void relocateStaff(std::shared_ptr<Staff::IEmployee> staff, const std::string &fromProject, const std::string &toProject);

        bool clean();
    };

}


#endif //STAFFDEMO_CSVPROJECTREPOSITORY_H
