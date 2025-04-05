#include "../Headers/Personal.h"
#include "../CustomLib/Generators.h"
#include <iomanip>
#include "../CustomLib/TranslationManager.h"

Personal::Personal() : Personal(genid(10, false), 0, 0) {}

Personal::Personal(const std::string& name, float worktime, float hourlyRate) :
    Employee(name, worktime), hourlyRate{hourlyRate} {}

Personal::~Personal() = default;

float Personal::getHourlyRate() const { return hourlyRate; }

void Personal::printInfo() const {

    // personal info
    std::cout << std::setw(15 + TranslationManager::instance().trlen("personal.printInfo.PersonalInfo", 2)) << std::setfill('-') <<
        TranslationManager::instance().tr("personal.printInfo.PersonalInfo") << " " << std::setw(15) << std::setfill('-') << "" << std::endl;
    std::cout << std::setfill(' ');

            // Name
    std::cout << std::left << std::setw(30) << TranslationManager::instance().tr("WORDS.Name") <<
            ": " << std::setw(15) << getName() << std::endl <<
            // ID
            std::setw(30) << TranslationManager::instance().tr("WORDS.ID") << ": " << std::setw(15) << getID() << std::endl <<
            // Work Time
            std::setw(30) << TranslationManager::instance().tr("personal.WorkTime") << ": " << std::setw(15) << getWorkTime() << std::endl <<
            // Hourly Rate
            std::setw(30) << TranslationManager::instance().tr("personal.HourlyRate") << ": " << std::setw(15) << getHourlyRate() << std::endl <<
            // Payment
            std::setw(30) << TranslationManager::instance().tr("personal.Payment") << ": " << std::setw(15) << getPayment() << std::endl;
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
    std::cout << std::setfill('-') << std::setw(30) << " Personal Info " << std::setw(15) << std::setfill('-') << "" << std::endl;
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
