#include <utility>

#include "../Headers/Personal.h"
#include <iomanip>


Personal::Personal() : Employee(), hourlyRate{0.0f} {}

Personal::Personal(std::string& name, float worktime, float hourlyRate) :
    Employee(name, worktime), hourlyRate{hourlyRate} {}

Personal::~Personal() = default;

float Personal::getHourlyRate() const { return hourlyRate; }

void Personal::printInfo() const {
    std::cout.width(31);
    std::cout.fill('-');
    std::cout << "Personal Info" << std::cout.fill('-') << std::endl << std::endl;
    std::cout << "Personal Info" << std::endl;
    std::cout << "Name: " << getName() << std::endl <<
                 "ID: " << getID() << std::endl <<
                 "Work time: " << getWorkTime() << std::endl <<
                 "Hourly rate: " << getHourlyRate() << std::endl <<
                 "Payment: " << getPayment() << std::endl;
    std::cout.width(31);
    std::cout.fill('-');
    std::cout << "" << std::endl;
}

Cleaner::Cleaner() : Personal() {}

Cleaner::Cleaner(std::string& name, float worktime, float hourlyRate) : Personal(name, worktime, hourlyRate) {}

Cleaner::~Cleaner() = default;

void Cleaner::calc() { payment = worktime * hourlyRate; }

void Cleaner::printInfo() const {
    Personal::printInfo();
}

Driver::Driver() : Personal(), nightBonus{0.0f} {}

Driver::Driver(std::string& name, float worktime, float hourlyRate, float nightBonus) :
    Personal(name, worktime, hourlyRate), nightBonus{nightBonus} {}

Driver::~Driver() = default;

float Driver::getNightBonus() const { return nightBonus; }

void Driver::calc() { payment = (payment * worktime) + nightBonus; }

void Driver::printInfo() const {
    std::cout << std::setw(13 + 30) << std::setfill('-') << "Personal Info" << std::endl;
//    std::cout.width(31);
//    std::cout.fill('-');
//    std::cout << "Personal Info" << std::endl;
//    std::cout << "Name: " << getName() << std::endl <<
//              "ID: " << getID() << std::endl <<
//              "Work time: " << getWorkTime() << std::endl <<
//              "Hourly rate: " << getHourlyRate() << std::endl <<
//              "Night bonus: " << getNightBonus() << std::endl <<
//              "Payment: " << getPayment() << std::endl;
//    std::cout.width(31);
//    std::cout.fill('-');
//    std::cout << "" << std::endl;
}
