#include <memory>
#include <utility>
#include "../../include/staff/Engineer.h"

namespace Staff {
    Engineer::Engineer(const std::string &name, const std::string &position, const std::string &id, int salary, std::shared_ptr<Project> project, float partOfBudget) :
            Personal(name, position, id, salary), project{project}, partOfBudget(partOfBudget)
    {}

    int Engineer::calcBudgetPart(float part, int budget) {
        return static_cast<int>(part * static_cast<float>(budget) / 100);
    }

    int Engineer::calcProAdditions() {
        return 0;
    }

    void Engineer::calc() {
        int PoB{0};
        if (auto proj = project.lock()) {
            PoB = proj->getBudget();
        }
        payment = Personal::calcBase(salary, worktime) + calcBudgetPart(partOfBudget, PoB) + calcProAdditions();
    }

    std::weak_ptr<Project> Engineer::getProject() {
        return project;
    }

    Programmer::Programmer(const std::string &name, const std::string &position, const std::string &id, int salary,
                           std::shared_ptr<Project> project, int proAdditions, float partOfBudget) :
            Engineer(name, position, id,salary, std::move(project), partOfBudget), proAdditions{proAdditions}
    {}

    void Programmer::addProAdditions(int add) {
        proAdditions += add;
    }

    void Programmer::removeProAdditions(int remove) {
        if (remove > proAdditions) throw std::overflow_error(std::string("Rem.value > proAddition"));
        proAdditions -= remove;
    }

    int Programmer::calcProAdditions() {
        return proAdditions;
    }

    Tester::Tester(const std::string &name, const std::string &position, const std::string &id, int salary,
                   std::shared_ptr<Project>project, int proAdditions, float partOfBudget) :
            Engineer(name, position, id, salary, project, partOfBudget), proAdditions{proAdditions}
    {}

    void Tester::addProAdditions(int add) {
        proAdditions += add;
    }

    void Tester::removeProAdditions(int remove) {
        if (remove > proAdditions) throw std::overflow_error(std::string("Rem.value > proAddition"));
        proAdditions -= remove;
    }

    int Tester::calcProAdditions() {
        return proAdditions;
    }

    TeamLeader::TeamLeader(const std::string &name, const std::string &position, const std::string &id, int salary,
                           std::shared_ptr<Project> project, int proAdditions, float partOfBudget, int teamHeading) :
            Programmer(name, position, id, salary, project, proAdditions, partOfBudget), teamHeading(teamHeading)
    {}

    int TeamLeader::calcHeads() {
        return teamHeading;
    }

    void TeamLeader::calc() {
        int PoB{0};
        if (auto proj = project.lock()) {
            PoB = proj->getBudget();
        }
        payment = Personal::calcBase(salary, worktime) + Engineer::calcBudgetPart(partOfBudget, PoB) + Programmer::calcProAdditions() + calcHeads();
    }

}
