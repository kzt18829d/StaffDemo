#ifndef STAFFDEMO_FACTORY_H
#define STAFFDEMO_FACTORY_H
#include <string>
#include <vector>

class Project {
private:
    std::string name;
    int budget;
public:
    Project(const std::string& name, int budget);
    std::string getName() const;
    int getBudget() const;
};

template <typename T>
std::vector<T*> makeStaff(const std::string& directory) {
    std::vector<T*> readStaff;
    // здесь происходит чтение из файла и запись в вектор
    return readStaff;
}


#endif //STAFFDEMO_FACTORY_H
