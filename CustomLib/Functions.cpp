#include "Functions.h"

const std::string SYMBOLS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefjhijklmnopqrstuvwxyz0123456789";
const std::string NUMBERS = "0123456789";
namespace GEN {
    std::random_device rd;
    std::mt19937 gen(rd());
}


std::string GEN::genid() { // generate id without parameters
    std::uniform_int_distribution<> dist(0, SYMBOLS.size()-1);
    std::string id;
    for (int i = 0; i < 10; ++i) id += SYMBOLS[dist(gen)];
    return id;
}

std::string GEN::genid(int lenght, bool num_token, bool let_token) { // generate id with parameters
    std::string id;
    size_t gen_type;

    std::uniform_int_distribution<> dist(0, SYMBOLS.size()-1);
    if ((!num_token && !let_token) || (num_token && let_token)) { gen_type = 0; }
    else if (!num_token) { dist = std::uniform_int_distribution<> (0, SYMBOLS.size() - 11); gen_type = 1; }
    else { dist = std::uniform_int_distribution<> (0, NUMBERS.size() - 1); gen_type = 2; }

    switch (gen_type) {
        case 0:
        case 1:
            for (int i{0}; i < lenght; i++) id += SYMBOLS[dist(gen)];
            break;
        case 2:
            for (int i{0}; i < lenght; i++) id += NUMBERS[dist(gen)];
            break;
    }
    return id;
}

std::vector<std::string> File::split(const std::string &line, char delim) {
    std::vector<std::string> result;
    std::stringstream ss(line);
    std::string value;

    while (std::getline(ss, value, delim)) result.push_back(value);
    return result;
}

void File::createFile(const std::string& dir) {
    std::ofstream file(dir, std::ios::out);
    if (!file.is_open()) throw std::ios::failure(std::string("Error of create file: Incorrect directory \'" + dir + "\""));
    else {file.close(); throw staff::except::InformationMessage("File created."); }

}


void File::openFile(const std::string &dir) {
    std::ifstream file(dir, std::ios_base::in);
    if (!file.is_open()) throw std::ios::failure(std::string("Error of read file: Incorrect directory \'" + dir + "\""));
    else {file.close(); throw staff::except::InformationMessage("File can be opened."); }

}

void File::saveSCV(const std::string &directory, const std::unordered_map<std::string, std::shared_ptr<Employee>> &STAFF_LIST,
                   const std::unordered_multimap<std::string, std::shared_ptr<Project>> &PROJECTS, char delim, char projectDelim) {
    std::fstream file(directory, std::ios_base::out | std::ios_base::trunc);
    if (!file.is_open()) throw std::ios_base::failure("Error, file couldn't be open.");
    file << "id;name;position;salary;project\n";
    for (const auto& [id, Employee]: STAFF_LIST) {
        file << Employee->getID() << delim;
        file << Employee->getName() << delim;
        file << Employee->getPosition() << delim;

        if (auto Personal_Class = std::dynamic_pointer_cast<Personal>(Employee)) {
            file << Personal_Class->getSalary() << delim;
        } else file << "" << delim;

        if (auto Engineer_Class = std::dynamic_pointer_cast<Engineer>(Employee)) {
            if (auto project = Engineer_Class->getProject().lock()) {
                file << project->getName();
            } else file << "";
        } else if (auto ProjectManager_Class = std::dynamic_pointer_cast<ProjectManager>(Employee)) {
            if (auto project = ProjectManager_Class->getProject().lock()){
                file << project->getName();
            } else file << "";
        } else if (auto SeniorManager_Class = std::dynamic_pointer_cast<SeniorManager>(Employee)) {
            const auto& projects = SeniorManager_Class->getProjects();
            for (auto& [projectName, project_weak] : projects) {
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

std::queue<TempEmloyee> File::loadSCV(const std::string &directory) {
    std::queue<TempEmloyee> empls;
    std::ifstream file(directory);
    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        auto fields = split(line);
        if (fields.size() != 5) continue;
        empls.push(TempEmloyee(fields[0], fields[1], fields[2], fields[3], fields[4]));
    }
    file.close();
    return empls;
}

std::set<std::string> File::splitUnic(const std::string &line, char delim) noexcept {
    std::set<std::string> split;
    std::stringstream ss(line);
    std::string value;
    try {
        while (std::getline(ss, value, delim)) split.insert(value);
    } catch (...) {}
    return split;
}


std::pair<bool, std::string> CEmployee::CreateEmployeePointers(const TempEmloyee &temp, std::unordered_map<std::string, std::shared_ptr<Employee>> &STAFF,
                          std::unordered_map<std::string, std::shared_ptr<Project>> &PROJECT_LIST) {
    try {
        if (STAFF[temp.id]) throw staff::except::previouslyAdded();
        if (temp.position == "cleaner") {
            STAFF[temp.id] = std::make_shared<Cleaner>(temp.name, temp.position, temp.id, std::stoi(temp.salary));
        }
        else if (temp.position == "driver") {
            STAFF[temp.id] = std::make_shared<Driver>(temp.name, temp.position, temp.id, std::stoi(temp.salary), std::stoi(temp.nBonus));
        }
        else if (temp.position == "seniorm") {
            std::map<std::string, std::weak_ptr<Project>> projects;
            std::set<std::string> rawProjectNames = File::splitUnic(temp.project, ':');
            for (const auto& projectName: rawProjectNames) {
                if (auto projectFindIterator = PROJECT_LIST.find(projectName); projectFindIterator != std::end(PROJECT_LIST)) {
                    projects[projectName] = projectFindIterator->second;
                }
                else {
                    PROJECT_LIST[projectName] = std::make_shared<Project>(projectName);
                    projects[projectName] = PROJECT_LIST[projectName];
                }
            }
            STAFF[temp.id] = std::make_shared<SeniorManager>(temp.name, temp.position, temp.id, std::stoi(temp.tHeading),
                                                             std::stof(temp.PoB), std::stoi(temp.PADD), projects); // unlock SM.Vector && lock SM.Map
            for (const auto& [projectName, weak]: projects) {
                if (auto project = weak.lock()) {
                    project->addMember(STAFF[temp.id]);
                }
            }
        }
        else {
            std::shared_ptr<Project> project;
            if (auto projectFindIterator = PROJECT_LIST.find(temp.project); projectFindIterator != std::end(PROJECT_LIST)) {
                project = projectFindIterator->second;
            }
            else project = std::make_shared<Project>(temp.project);

            if (temp.position == "programmer") {
                STAFF[temp.id] = std::make_shared<Programmer>(temp.name, temp.position, temp.id,
                                                              std::stoi(temp.salary), project, std::stoi(temp.PADD),
                                                              std::stof(temp.PoB));
            }
            else if (temp.position == "tester") {
                STAFF[temp.id] = std::make_shared<Tester>(temp.name, temp.position, temp.id,
                                                          std::stoi(temp.salary), project, std::stoi(temp.PADD),
                                                          std::stof(temp.PoB));
            }
            else if (temp.position == "timlid") {
                STAFF[temp.id] = std::make_shared<TeamLeader>(temp.name, temp.position, temp.id,
                                                              std::stoi(temp.salary), project, std::stoi(temp.PADD),
                                                              std::stof(temp.PoB), std::stoi(temp.tHeading));
            }
            else if (temp.position == "projectm") {
                STAFF[temp.id] = std::make_shared<ProjectManager>(temp.name, temp.position, temp.id,
                                                                  std::stoi(temp.tHeading), std::stof(temp.PoB),
                                                                  std::stoi(temp.PADD), project);
            }
            project->addMember(STAFF[temp.id]);
            PROJECT_LIST[temp.project] = std::move(project);
        }
    }
    catch (staff::except::StaffException &staffException) { return {false, staffException.what()}; }
    catch (std::exception &exception) { return {false, exception.what()}; }
    return {true, "Done"};
}
