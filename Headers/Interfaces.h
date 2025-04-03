#ifndef STAFFDEMO_INTERFACES_H
#define STAFFDEMO_INTERFACES_H

class ProjectBudget {
public:
    virtual int calcBudgetPart(float part, int budget) = 0;
    virtual int calcProAdditions() = 0;
};

class Heading {
public:
    virtual int calcHeads(int heads) = 0;
};


#endif //STAFFDEMO_INTERFACES_H
