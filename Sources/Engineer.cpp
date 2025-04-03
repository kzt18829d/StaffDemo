//
// Created by hid3h on 03.04.2025.
//

#include "../Headers/Engineer.h"

Engineer::Engineer(const std::string &name, float worktime, float hourlyRate, const Project& project) :
        Personal(name, worktime, hourlyRate), project{project}, bonusForProject{0.0f} {}

Engineer::~Engineer() = default;

int Engineer::calcBudgetPart(float part, int budget) { // интерфейс, его нужно сделать
    return 0;
}

void Engineer::calc() { payment = (worktime * hourlyRate) + bonusForProject; }

Tester::Tester(const std::string &name, float worktime, float hourlyRate, const Project &project) :
    Engineer(name, worktime, hourlyRate, project) {}

Tester::~Tester() = default;

int Tester::calcProAdditions() { // ну это расчёт выплат, я не придумал, поэтому пишешь ты, я уже заебался. классы допишу, ты интерфейсы, дальше посмотрим
    return 0;
}

Programmer::Programmer(const std::string &name, float worktime, float hourlyRate, const Project &project) :
    Engineer(name, worktime, hourlyRate, project), premier{0} {}

Programmer::~Programmer() = default;

int Programmer::calcProAdditions() { // здесь то же, что и в class Tester, ебись с этим)))))))
    return 0;
}

TeamLeader::TeamLeader(const std::string &name, float worktime, float hourlyRate, const Project &project) :
        Programmer(name, worktime, hourlyRate, project) {}

TeamLeader::~TeamLeader() = default;

int TeamLeader::calcHeads(int heads) {
    /*
     * ну тут тоже ты
     * и параметр возможно надо будет изменить. не возможно, а точно скорее всего + class Project подстроить
     * я писал это всё не особо думая и выстраивая схемы взаимодействия, так что нужно будет редактировать всё ещё
     * */
    return 0; // GPT выключил блять, кому сказал
}

void TeamLeader::calc() {
    Engineer::calc();
}