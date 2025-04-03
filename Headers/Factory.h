//
// Created by hid3h on 03.04.2025.
//

#ifndef STAFFDEMO_FACTORY_H
#define STAFFDEMO_FACTORY_H
#include <string>
#include <vector>

class Project {
private:
    std::string projectName;
    float budget;
public:
    Project();
    Project(std::string  projectName, float budget);
    ~Project();

    std::string getProjectName() const;
    float getBudget() const;

    void showProjectInfo() const;
};

template <typename T>
std::vector<T*> makeStaff(const std::string& directory) {
    std::vector<T*> readStaff;
    // здесь происходит чтение из файла и запись в вектор
    return readStaff;
}


#endif //STAFFDEMO_FACTORY_H
