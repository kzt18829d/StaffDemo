#ifndef STAFFDEMO_ENGINEER_H
#define STAFFDEMO_ENGINEER_H

#include <string>

#include "Personal.h"
#include "Factory.h"
#include "StaffInterfaces.h"
namespace Staff {
    ///@brief Абстрактный класс для наследников Engineer
    ///@param [in] name Имя единицы персонала
    ///@param [in] position Занимаемая должность
    ///@param [in] id Идентификатор единицы персонала, уникальное значение (16 знаков, 0-9 & a-z & A-Z)
    ///@param [in] salary Почасовая ставка
    ///@param [in] project Проект, к которому привязан инженер
    ///@param [in] partOfBudget Процент надбавки за участие в проекте
    ///@TPositon engineer
    ///@see Personal
    ///@see ProjectBudget
    ///@ingroup Staff
    class Engineer : public Personal, public ProjectBudget {
    protected:
        std::weak_ptr<Project> project;
        float partOfBudget;
    public:
        Engineer(const std::string& name, const std::string& position, const std::string& id, int salary, std::shared_ptr<Project> project=nullptr, float partOfBudget=0.0f);
        virtual ~Engineer() override = default;

        int calcBudgetPart(float part, int budget) override;
        int calcProAdditions() override;

        std::weak_ptr<Project> getProject();

        void calc() override;
    };

    ///@brief Класс должности Programmer
    ///@param [in] name Имя единицы персонала
    ///@param [in] position Занимаемая должность
    ///@param [in] id Идентификатор единицы персонала, уникальное значение (16 знаков, 0-9 & a-z & A-Z)
    ///@param [in] salary Почасовая ставка
    ///@param [in] project Проект, к которому привязан инженер
    ///@param [in] proAdditions Фиксированная надбавка за написание кода (не зависит от их количества)
    ///@param [in] partOfBudget Процент надбавки за участие в проекте
    ///@TPositon programmer
    ///@see Engineer
    ///@ingroup Staff
    class Programmer : public Engineer {
    private:
        int proAdditions;
    public:
        Programmer(const std::string& name, const std::string& position, const std::string& id,
                   int salary, std::shared_ptr<Project> project= nullptr, int proAdditions=0, float partOfBudget=0.0f);
        ~Programmer() override = default;

        void addProAdditions(int add);
        void removeProAdditions(int remove); // добавить обработку исключений при вызове

        int calcProAdditions() override;
    };

    ///@brief Класс должности Tester
    ///@param [in] name Имя единицы персонала
    ///@param [in] position Занимаемая должность
    ///@param [in] id Идентификатор единицы персонала, уникальное значение (16 знаков, 0-9 & a-z & A-Z)
    ///@param [in] salary Почасовая ставка
    ///@param [in] project Проект, к которому привязан инженер
    ///@param [in] proAdditions Фиксированная надбавка за найденные баги (не зависит от их количества)
    ///@param [in] partOfBudget Процент надбавки за участие в проекте
    ///@TPositon tester
    ///@see Engineer
    ///@ingroup Staff
    class Tester : public Engineer {
    private:
        int proAdditions;
    public:
        Tester(const std::string& name, const std::string& position, const std::string& id, int salary, std::shared_ptr<Project> project = nullptr, int proAdditions=0, float partOfBudget=0.0f);
        ~Tester() override = default;

        void addProAdditions(int add);
        void removeProAdditions(int remove); // добавить обработку исключений при вызове

        int calcProAdditions() override;
    };

    ///@brief Класс должности TeamLeader
    ///@param [in] name Имя единицы персонала
    ///@param [in] position Занимаемая должность
    ///@param [in] id Идентификатор единицы персонала, уникальное значение (16 знаков, 0-9 & a-z & A-Z)
    ///@param [in] salary Почасовая ставка
    ///@param [in] project Проект, которым руководит тимлид
    ///@param [in] proAdditions Фиксированная надбавка за написание кода
    ///@param [in] partOfBudget Процент надбавки за участие в проекте
    ///@param [in] teamHeading Надбавка за руководство над проектом (фиксированная, без зависимости от количества подчинённых)
    ///@TPositon teamlid
    ///@see Engineer
    ///@ingroup Staff
    class TeamLeader : public Programmer, public Heading {
    private:
        int teamHeading;
    public:
        TeamLeader(const std::string& name, const std::string& position, const std::string& id, int salary, std::shared_ptr<Project> project = nullptr, int proAdditions=0, float partOfBudget=0.0f, int teamHeading=0);
        ~TeamLeader() override = default;

        int calcHeads() override;

        void calc() override;
    };
}


#endif //STAFFDEMO_ENGINEER_H
