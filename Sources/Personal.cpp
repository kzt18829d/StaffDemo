#include <utility>

#include "../Headers/Personal.h"
#include "../CustomLib/Generators.h"
#include <iomanip>


Personal::Personal() : Personal(genid(10, false), 0, 0) {}

Personal::Personal(const std::string& name, float worktime, float hourlyRate) :
    Employee(name, worktime), hourlyRate{hourlyRate} {}

Personal::~Personal() = default;

float Personal::getHourlyRate() const { return hourlyRate; }

void Personal::printInfo() const {
    std::cout << std::setw(30) << std::setfill('-') << " Personal Info " << std::setw(15) << std::setfill('-') << "" << std::endl;
    std::cout << std::setfill(' ');
    std::cout << std::left << std::setw(30) << "Name: " << std::setw(15) << getName() << std::endl <<
              std::setw(30) << "ID: " << std::setw(15) << getID() << std::endl <<
              std::setw(30) << "Work time: " << std::setw(15) << getWorkTime() << std::endl <<
              std::setw(30) << "Hourly rate: " << std::setw(15) << getHourlyRate() << std::endl <<
              std::setw(30) << "Payment: " << std::setw(15) << getPayment() << std::endl;
    std::cout << std::setfill('-') << std::setw(45) << "-" << std::endl;
    std::cout << std::setfill(' ');
}

Cleaner::Cleaner() : Personal() {}

Cleaner::Cleaner(const std::string& name, float worktime, float hourlyRate) : Personal(name, worktime, hourlyRate) {}

Cleaner::~Cleaner() = default;

void Cleaner::calc() { payment = worktime * hourlyRate; }

void Cleaner::printInfo() const { Personal::printInfo(); }

Driver::Driver() : Personal(), nightBonus{0.0f} {}

Driver::Driver(std::string& name, float worktime, float hourlyRate, float nightBonus) :
    Personal(name, worktime, hourlyRate), nightBonus{nightBonus} {}

Driver::~Driver() = default;

float Driver::getNightBonus() const { return nightBonus; }

void Driver::calc() { payment = (payment * worktime) + nightBonus; }

void Driver::printInfo() const {
    std::cout << std::setw(30) << std::setfill('-') << " Personal Info " << std::setw(15) << std::setfill('-') << "" << std::endl;
    std::cout << std::setfill(' ');
    std::cout << std::left << std::setw(30) << "Name: " << std::setw(15) << getName() << std::endl <<
                std::setw(30) << "ID: " << std::setw(15) << getID() << std::endl <<
                std::setw(30) << "Work time: " << std::setw(15) << getWorkTime() << std::endl <<
                std::setw(30) << "Hourly rate: " << std::setw(15) << getHourlyRate() << std::endl <<
                std::setw(30) << "Night Bonus: " << std::setw(15) << getNightBonus() << std::endl <<
                std::setw(30) << "Payment: " << std::setw(15) << getPayment() << std::endl;
    std::cout << std::setfill('-') << std::setw(45) << "-" << std::endl;
//    std::cout.width(31);
//    std::cout.fill('-');
//    std::cout << "Personal Info" << std::endl;
//    std::cout << "Name: " << getName() << std::endl <<
//              "ID: " << getID() << std::endl <<
//              "Work time: " << getWorkTime() << std::endl <<
//              "Hourly rate: " << getHourlyRate() << std::endl <<
//              "Night bonusForProject: " << getNightBonus() << std::endl <<
//              "Payment: " << getPayment() << std::endl;
//    std::cout.width(31);
//    std::cout.fill('-');
//    std::cout << "" << std::endl;
}
