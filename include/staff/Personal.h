#ifndef STAFFDEMO_PERSONAL_H
#define STAFFDEMO_PERSONAL_H

#include "IEmployee.h"
#include "StaffInterfaces.h"

namespace Staff{
    ///@brief Шаблон для классов-наследников Personal
    ///@details Абстрактный класс, от которого наследуются большинство единиц персонала.
    ///@param [in] name Имя единицы персонала
    ///@param [in] position Занимаемая должность
    ///@param [in] id Идентификатор единицы персонала, уникальное значение (16 знаков, 0-9 & a-z & A-Z)
    ///@param [in] salary Почасовая ставка
    ///@TPositon personal
    ///@see IEmployee
    ///@ingroup Staff
    class Personal : public IEmployee, public WorkBaseTime {
    protected:
        int salary;
    public:
        Personal(const std::string& name, const std::string& position, const std::string& id, int salary);
        virtual ~Personal() override = default;

        int calcBase(int salary_, int worktime_) override;
        int calcBonus() override;

        int getSalary() const;

        void calc() override;
    };

    ///@brief Класс должности Cleaner
    ///@param [in] name Имя единицы персонала
    ///@param [in] position Занимаемая должность
    ///@param [in] id Идентификатор единицы персонала, уникальное значение (16 знаков, 0-9 & a-z & A-Z)
    ///@param [in] salary Почасовая ставка
    ///@TPositon cleaner
    ///@see Personal
    ///@ingroup Staff
    class Cleaner : public Personal {
    public:
        Cleaner(const std::string& name, const std::string& position, const std::string& id, int salary);
        ~Cleaner() override = default;
    };

    ///@brief Класс должности Driver
    ///@param [in] name Имя единицы персонала
    ///@param [in] position Занимаемая должность
    ///@param [in] id Идентификатор единицы персонала, уникальное значение (16 знаков, 0-9 & a-z & A-Z)
    ///@param [in] salary Почасовая ставка
    ///@param [in] nBonus бонус за ночные смены
    ///@TPositon driver
    ///@see Personal
    ///@ingroup Staff
    class Driver : public Personal {
    private:
        int nightBonus;
    public:
        Driver(const std::string& name, const std::string& position, const std::string& id, int salary, int nBonus);
        ~Driver() override = default;
        int calcBonus() override;
    };
}



#endif //STAFFDEMO_PERSONAL_H
