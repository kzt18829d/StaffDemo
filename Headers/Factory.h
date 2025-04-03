//
// Created by hid3h on 03.04.2025.
//

#ifndef STAFFDEMO_FACTORY_H
#define STAFFDEMO_FACTORY_H
#include <string>

class Project {
private:
    std::string projectName;
    float budget;
public:
    Project();
    Project(std::string  projectName, float budget);
    ~Project();
};

#endif //STAFFDEMO_FACTORY_H
