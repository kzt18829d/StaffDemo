#ifndef STAFFDEMO_ENGINEER_H
#define STAFFDEMO_ENGINEER_H

#include <string>

#include "Personal.h"
#include "Factory.h"
#include "StaffInterfaces.h"
namespace StaffDemo::Core::Staff {
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
