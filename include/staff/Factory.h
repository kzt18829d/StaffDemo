#ifndef STAFFDEMO_FACTORY_H
#define STAFFDEMO_FACTORY_H

#include <string>
#include <vector>
#include <set>
#include <memory>
#include "IEmployee.h"

#include "../utils/StaffExceptions.h"

namespace StaffDemo::Staff {

    ///@brief Шаблон временного хранилища единицы проекта
    ///@details Предназначен для временного хранения единицы проекта при передаче на чтение/запись в IStorageProvider.
    ///Хранит исключительно название проекта
    ///@param [in] name Название проекта
    ///@ingroup Staff
    struct TempProject {
        std::string name;
    };

    ///@brief Класс проекта
    ///@details Хранит информацию о проекте и указатель на сотрудников, входящих в проект
    ///@param [in] name Название проекта
    ///@param [in] budget Бюджет проекта
    ///@param members Вектор сотрудников, участвующих в проекте. Не принимается конструктором.
    ///@ingroup Staff
    class Project {
    private:
        std::string name;
        int budget;
        std::vector<std::weak_ptr<IEmployee>> members;
    public:
        explicit Project(std::string  name, int budget=0);

        std::string getName() const;
        int getBudget() const;

        std::vector<std::weak_ptr<IEmployee>> getMembers(); ///< @return vector

        void addMember(std::weak_ptr<IEmployee> member); ///< Add by pointer
        void removeMember(std::weak_ptr<IEmployee> member); ///< Remove by pointer
        void removeMember(const std::string& memberID); ///< Remove by ID
        void removeMember(); ///< Remove last added

        bool operator==(const Project& other) const;
        bool operator!=(const Project& other) const;
        bool operator<(const Project& other) const;
        bool operator>(const Project& other) const;
        bool operator<=(const Project& other) const;
        bool operator>=(const Project& other) const;

    };
}

#endif //STAFFDEMO_FACTORY_H
