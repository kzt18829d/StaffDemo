#ifndef STAFFDEMO_IPROJECTREPOSITORY_H
#define STAFFDEMO_IPROJECTREPOSITORY_H
#include <memory>
#include <vector>
#include <map>
#include "../staff/Factory.h"
#include "../staff/IEmployee.h"

///@defgroup Interface Интерфейс
namespace StaffDemo::Interface {
    ///@brief Интерфейс репозитория проектов
    ///@details Содержит чистые виртуальные методы взаимодействия с данными проектов внутри репозитория
    ///@ingroup Interface
    class IProjectRepository {
    public:
        virtual ~IProjectRepository() = 0;
        virtual void add(std::shared_ptr<Staff::Project> project) = 0;
        virtual void remove(std::shared_ptr<Staff::Project> project) = 0;

        virtual std::map<std::string, std::shared_ptr<Staff::Project>> getProjects() const = 0;
        virtual std::vector<std::weak_ptr<Staff::IEmployee>> getStaff(std::shared_ptr<Staff::Project> project) const = 0;
        virtual std::vector<std::weak_ptr<Staff::IEmployee>> getStaff(const std::string& projectName) const = 0;

        virtual void addStaff(std::shared_ptr<Staff::IEmployee>, std::shared_ptr<Staff::Project> project) = 0;
        virtual void addStaff(std::shared_ptr<Staff::IEmployee>, const std::string& project) = 0;

        virtual void removeStaff(std::shared_ptr<Staff::IEmployee>, std::shared_ptr<Staff::Project> project) = 0;
        virtual void removeStaff(std::shared_ptr<Staff::IEmployee>, const std::string& project) = 0;

        // ну мало ли
        virtual void relocateStaff(std::shared_ptr<Staff::IEmployee> staff, std::shared_ptr<Staff::Project> fromProject, std::shared_ptr<Staff::Project> toProject) = 0;
        virtual void relocateStaff(std::shared_ptr<Staff::IEmployee> staff, const std::string& fromProject, const std::string& toProject) = 0;
        virtual void relocateStaff(std::shared_ptr<Staff::IEmployee> staff, std::shared_ptr<Staff::Project> fromProject, const std::string& toProject) = 0;
        virtual void relocateStaff(std::shared_ptr<Staff::IEmployee> staff, const std::string& fromProject, std::shared_ptr<Staff::Project> toProject) = 0;
    };
}


#endif //STAFFDEMO_IPROJECTREPOSITORY_H
