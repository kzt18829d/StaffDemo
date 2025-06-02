#ifndef STAFFDEMO_IEMPLOYEE_H
#define STAFFDEMO_IEMPLOYEE_H
#include <string>
#include <iostream>
#include "staff_enum.h"

///@defgroup Staff Персонал
using namespace StaffDemo::Core::ENUM;

namespace StaffDemo::Staff {
//    /@Positions (pos[posInFile]):
//    /@Cleaner[cleaner] @tDriver[driver]
//    /@Programmer[programmer] @Tester[tester] @TeamLeader[timlid]
//    /@ProjectManager[projectm] @SeniorManager[seniorm]

    ///@brief Класс-интерфейс персонала
    ///@details Базовый абстрактный класс-интерфейс, от которого прочие классы персонала.
    ///Содержит общие параметры всех классов сотрудника
    ///@param [in] name Имя единицы персонала
    ///@param [in] position Занимаемая должность
    ///@param [in] id Идентификатор единицы персонала, уникальное значение (16 знаков, 0-9 & a-z & A-Z)
    ///@TPosition employee
    ///@ingroup Staff
    ///@ingroup Interface
    class IEmployee {
    protected:
        std::string id;
        std::string name;
        std::string position;
        int worktime;
        int payment;
    public:
        IEmployee(const std::string &name, const std::string &position, const std::string &id);
        virtual ~IEmployee();
        void setWorkTime(int worktime_);
        virtual void calc() = 0;

        std::string getID() const;
        std::string getName() const;
        std::string getPosition() const;
        int getWorkTime() const;
        int getPayment() const;

        bool operator==(const IEmployee &other) const;
        bool operator!=(const IEmployee &other) const;
    };
}




#endif //STAFFDEMO_IEMPLOYEE_H
