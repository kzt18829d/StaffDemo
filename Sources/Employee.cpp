#include "../Headers/Employee.h"
#include <iostream>
#include <limits>
#include <utility>
#include "../CustomLib/Generators.h"
#include "../CustomLib/TranslationManager.h"

Employee::Employee() : Employee(genid(10, false), 0) {}

Employee::Employee(std::string  name, float worktime) :
        id{genid(12)}, name{std::move(name)}, worktime{worktime}, payment{0.0f} { };

void Employee::setWorkTime() {
    do {
//        std::cout << "Enter employee work time (hours): ";
        std::cout << TranslationManager::instance().tr("employee.setWorkTime.t1") << ": ";
        std::cin >> worktime;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << TranslationManager::instance().tr("ERRORS.CIN.INVALID_ARGUMENT") << " "
                << TranslationManager::instance().tr("ERRORS.repeat") << std::endl;
//            std::cerr << "Error, invalid_argument. Repeat. . ." << std::endl;
        } else break;
    } while(!std::cin.fail());
}

Employee::~Employee() = default;

float Employee::getWorkTime() const { return worktime; }

std::string Employee::getID() const { return id; }

std::string Employee::getName() const { return name; }

float Employee::getPayment() const { return payment; }
