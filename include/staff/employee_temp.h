#ifndef STAFFDEMO_EMPLOYEE_TEMP_H
#define STAFFDEMO_EMPLOYEE_TEMP_H
#include <string>

namespace Staff {

    ///@brief Шаблон временного хранилища единицы персонала
    ///@details Предназначен для использования в качестве посредника между функциями, не привязанный к конкретному типу IEmployee,
    ///обладающий private/protected-характеристиками каждого из наследников IEmployee.
    ///Для создания структуры не обязательно заполнение всех полей
    ///@param [in] id Идентификатор единицы персонала, уникальное значение (16 знаков, 0-9 & a-z & A-Z)
    ///@param [in] name Имя единицы персонала
    ///@param [in] position Занимаемая должность
    ///@param [in] salary Почасовая ставка
    ///@param [in] project Проект
    ///@param [in] nBonus Ночной бонус
    ///@param [in] PoB Надбавка за участие в проекте
    ///@param [in] PADD Надбавка за ошибки/код
    ///@param [in] tHeading Надбавка за руководство проектом
    ///@ingroup Staff
    struct TempEmloyee {
        std::string id;
        std::string name;
        std::string position;
        std::string salary;
        std::string project;
        std::string nBonus;
        std::string PoB;
        std::string PADD;
        std::string tHeading;
    };

} // Staff

#endif //STAFFDEMO_EMPLOYEE_TEMP_H
