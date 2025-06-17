#include "data/CSV/CSVSPStorageProvider.h"
#include "utils/Split.h"
#include <sstream>
#include <fstream>
#include "staff/Personal.h"
#include "staff/Engineer.h"
#include "staff/Manager.h"
#include "staff/employee_temp.h"

using namespace Utils;

namespace Data::StorageProvider {

    std::pair<std::queue<Staff::TempEmloyee>, std::vector<Staff::TempProject>> CSVSPStorageProvider::load() {
//        FileLogger::instance().log("-LOAD StaffDemo::Core::StorageProvider::CSVProjectRepository.load is called.");
        std::ifstream CSV(directory, std::ios::in);
        if (!CSV.is_open()) {
//            FileLogger::instance().log("-LOAD StaffDemo::Core::StorageProvider::CSVProjectRepository.load error of -OPEN \"" + directory + "\" with std::ios::in.", Utils::Logger::ERROR);
            throw std::ios_base::failure("Error, file couldn't be open.");
        }
//        FileLogger::instance().log("-LOAD StaffDemo::Core::StorageProvider::CSVProjectRepository.load -OPEN \"" + directory + "\" with std::ios::in.");
        std::queue<Staff::TempEmloyee> staffs;
        std::vector<Staff::TempProject> projects;

        std::string line;
        std::getline(CSV, line);

//        FileLogger::instance().log("-LOAD StaffDemo::Core::StorageProvider::CSVProjectRepository.load parsing file.");

        while (std::getline(CSV, line)) {
            std::vector<std::string> fields = split(line, ';');
            if (fields.size() != 5) continue;
            staffs.push(Staff::TempEmloyee(fields[0], fields[1], fields[2], fields[3], fields[4]));
            if (!fields[4].empty()) projects.push_back(Staff::TempProject(fields[4]));
        }

//        FileLogger::instance().log("-LOAD StaffDemo::Core::StorageProvider::CSVProjectRepository.load is complete");

        CSV.close();
//        FileLogger::instance().log("-LOAD StaffDemo::Core::StorageProvider::CSVProjectRepository.load -CLOSE \"" + directory + "\".");
//        FileLogger::instance().log("-LOAD StaffDemo::Core::StorageProvider::CSVProjectRepository.load -COMPLETED.");
        return {staffs, projects};
    }

    //save second
    void CSVSPStorageProvider::save(const std::vector<Staff::TempEmloyee>& staffs, const std::vector<Staff::TempProject>& projects) {
        std::ofstream CSV(directory, std::ios_base::out | std::ios_base::trunc);
        char delim = ';';
        if (!CSV.is_open()) {

            throw std::ios_base::failure("Error, file couldn't be open.");
        }
        CSV << "id;name;position;salary;project\n";
        for (const auto& staff: staffs) {
            CSV << staff.id << delim;
            CSV << staff.name << delim;
            CSV << staff.position << delim;
            CSV << ((staff.salary == "0" || staff.salary.empty()) ? std::string("") : staff.salary) << delim;
            CSV << (staff.project.empty() ? std::string("") : staff.project) << delim;
        }
        CSV.close();
    }

    // save_base
    void CSVSPStorageProvider::save(const std::map<std::string, std::weak_ptr<Staff::IEmployee>> &staffs,
                                    const std::map<std::string, std::weak_ptr<Staff::Project>> &projects) {
        char delim = ';';
        std::fstream file(directory, std::ios_base::out | std::ios_base::trunc);
        if (!file.is_open()) {

            throw std::ios_base::failure("Error, file couldn't be open.");
        }
        file << "id;name;position;salary;project\n";
        for (const auto& [id, Employee]: staffs) {
            file << Employee.lock()->getID() << delim;
            file << Employee.lock()->getName() << delim;
            file << Employee.lock()->getPosition() << delim;

            if (auto Personal_Class = std::dynamic_pointer_cast<Staff::Personal>(Employee.lock())) {
                file << Personal_Class->getSalary() << delim;
            } else file << "" << delim;

            if (auto Engineer_Class = std::dynamic_pointer_cast<Staff::Engineer>(Employee.lock())) {
                if (auto project = Engineer_Class->getProject().lock()) {
                    file << project->getName();
                } else file << "";
            } else if (auto ProjectManager_Class = std::dynamic_pointer_cast<Staff::ProjectManager>(Employee.lock())) {
                if (auto project = ProjectManager_Class->getProject().lock()){
                    file << project->getName();
                } else file << "";
            } else if (auto SeniorManager_Class = std::dynamic_pointer_cast<Staff::SeniorManager>(Employee.lock())) {
                const auto& projects_ = SeniorManager_Class->getProjects();
                for (auto& [projectName, project_weak] : projects_) {
                    file << ':';
                    if (auto project = project_weak.lock()) {
                        file << project->getName();
                    } else file << "";
                }
            }
            file << '\n';
        }
        file.close();
    }

    void CSVSPStorageProvider::setDirectory(std::string &directory) {
        directory = std::move(directory);
    }

    std::vector<std::string> CSVSPStorageProvider::split(const std::string &line, char delim) {
        std::vector<std::string> result;
        std::stringstream ss(line);
        std::string value;

        while (std::getline(ss, value, delim)) result.push_back(value);
        return result;
    }

    CSVSPStorageProvider::CSVSPStorageProvider() = default;
}