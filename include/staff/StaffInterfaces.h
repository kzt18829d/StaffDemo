#ifndef STAFFDEMO_STAFFINTERFACES_H
#define STAFFDEMO_STAFFINTERFACES_H

///@namespace Staff
namespace Staff {
    ///@brief Интерфейс для персонала
    ///@ingroup Interface
    ///@see Personal
    struct WorkBaseTime {
        virtual int calcBase(int salary_, int worktime_) = 0;
        virtual int calcBonus() = 0;
        virtual ~WorkBaseTime() = default;
    };

    ///@brief Интерфейс для персонала
    ///@ingroup Interface
    ///@ingroup Interface
    struct ProjectBudget {
        virtual int calcBudgetPart(float part, int budget) = 0;
        virtual int calcProAdditions() = 0;
        virtual ~ProjectBudget() = default;
    };

    ///@brief Интерфейс для персонала
    ///@ingroup Interface
    ///@ingroup Interface
    struct Heading {
        virtual int calcHeads() = 0;
        virtual ~Heading() = default;
    };
}


#endif //STAFFDEMO_STAFFINTERFACES_H
