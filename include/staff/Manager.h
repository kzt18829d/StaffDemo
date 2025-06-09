#ifndef STAFFDEMO_MANAGER_H
#define STAFFDEMO_MANAGER_H
#include "IEmployee.h"
#include "StaffInterfaces.h"
#include "Factory.h"
#include <memory>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

namespace Staff {
    ///@brief Класс должности ProjectManager
    ///@param [in] name Имя единицы персонала
    ///@param [in] position Занимаемая должность
    ///@param [in] id Идентификатор единицы персонала, уникальное значение (16 знаков, 0-9 & a-z & A-Z)
    ///@param [in] heading Надбавка за руководство (Фиксированная, не зависящая от количества подчинённых)
    ///@param [in] partOfBudget Процент надбавки за участие в проекте
    ///@param [in] proAddition Фиксированная надбавка за написание кода
    ///@param [in] project Проект, которым руководит менеджер
    ///@TPositon projectm
    ///@see IEmployee
    ///@ingroup Staff
    class ProjectManager : public IEmployee, public ProjectBudget, public Heading {
    private:
        std::weak_ptr<Project> project;
    protected:
        float partOfBudget;
        int heading;
        int proAddition;
    public:
        ProjectManager(const std::string& name, const std::string& position, const std::string& id, int heading, float partOfBudget, int proAddition, std::shared_ptr<Project> project=nullptr);
        ~ProjectManager() override = default;

        int calcBudgetPart(float part, int budget) override;
        int calcProAdditions() override;
        int calcHeads() override;

        std::weak_ptr<Project> getProject();

        void calc() override;
    };

    ///@brief Класс должности SeniorManager
    ///@param [in] name Имя единицы персонала
    ///@param [in] position Занимаемая должность
    ///@param [in] id Идентификатор единицы персонала, уникальное значение (16 знаков, 0-9 & a-z & A-Z)
    ///@param [in] heading Надбавка за руководство (Фиксированная, не зависящая от количества подчинённых)
    ///@param [in] partOfBudget Процент надбавки за участие в проекте
    ///@param [in] proAddition Фиксированная надбавка за написание кода
    ///@param [in] projectsMap Карта проектов, которыми руководит менеджер
    ///@TPositon seniorm
    ///@see IEmployee
    ///@ingroup Staff
    class SeniorManager : public IEmployee, public ProjectBudget, public Heading {
    private:
        std::map<std::string, std::weak_ptr<Project>> projects;
//    std::vector<std::weak_ptr<Project>> projects;
        float partOfBudget;
        int heading;
        int proAddition;
    public:
        SeniorManager(const std::string& name, const std::string& position, const std::string& id, int heading, float partOfBudgets, int proAddition, std::map<std::string, std::weak_ptr<Project>> projectsMap);
//    SeniorManager(const std::string& name, const std::string& position, const std::string& id, int heading, float partOfBudgets, int proAddition, std::vector<std::weak_ptr<Project>> projectsVector);
        ~SeniorManager() override = default;

        int calcBudgetPart(float part, int budget) override;
        int calcProAdditions() override;
        int calcHeads() override;

        void calc() override;

        std::map<std::string, std::weak_ptr<Project>> getProjects();
        std::vector<std::string> getProjectsNames();

        void addProject(std::weak_ptr<Project> project);
        void removeProject(std::weak_ptr<Project> project);
//    void removeProject(const std::pair<const std::basic_string<char>, std::weak_ptr<Project>> projectName_);
    };
}


#endif //STAFFDEMO_MANAGER_H
