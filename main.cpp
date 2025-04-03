#include <iostream>
#include "Headers/Employee.h"
#include "Headers/Personal.h"
#include "CustomLib/Generators.h"
#include <iostream>
#include <vector>
#include <iomanip>



int main() {
    std::vector<Employee*> STAFF;
    std::string name = "Stepan";
    Driver d1(name, 100, 100, 30);
    d1.printInfo();
    d1.calc();
    d1.printInfo();
}