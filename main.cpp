#include <string>
#include <unordered_map>
#include "include/core/staff/Employee.h"
#include "include/core/staff/Factory.h"
#include "utils/TranslationManager.h"
#include "utils/Logger.h"
#include "TUI.h"

static const std::size_t WIN_WIDTH = 118;
static const std::size_t WIN_HEIGHT = 28;

std::string getTime() {
    const time_t now = time(nullptr);
    std::string time_str = ctime(&now);

    if (!time_str.empty() && time_str.back() == '\n') {
        time_str.pop_back();
    }

    std::replace(time_str.begin(), time_str.end(), ' ', '_');
    std::replace(time_str.begin(), time_str.end(), ':', '-');

    return time_str;
}

int main(int argc, char *argv[]){
    using namespace StaffDemo::Utils;
    using namespace StaffDemo::Utils;

#ifdef NDEBUG
    std::string localizationDataDirectory = "LNG.json";
    std::stringstaffDataDirectory = "Staff_Data.csv";
    std::string logFileDirectory = "logs/log-" + getTime();
#else
    std::string localizationDataDirectory = "./Data_local/newLangs.json";
    std::string staffDataDirectory = "./Data_local/Staff_Data.csv";
    std::string logFileDirectory = "./Data_local/logs/log-" + getTime();
#endif
    try {
        FileLogger::initialize(logFileDirectory);
    } catch (...) {
        std::cout << "File don't load." << std::endl;
    }
    FileLogger::instance().log("StaffDemo started.");
    FileLogger::instance().log("StaffDemo::Utils::FileLogger started.");

    try {
        TranslationManager::instance().loadJson(localizationDataDirectory, "en");
    } catch (std::exception& exception) {
        FileLogger::instance().log("StaffDemo::Utils::TranslationManager --" + std::string(exception.what()), StaffDemo::Utils::Logger::Logger::ERROR);
        exit(1454);
    }
    FileLogger::instance().log("StaffDemo::Utils::TranslationManager started.");
    FileLogger::instance().flush();


    std::unordered_map<std::string, std::shared_ptr<StaffDemo::Core::Staff::Employee>>STAFF;
    std::unordered_map<std::string, std::shared_ptr<StaffDemo::Core::Staff::Project>>PROJECTS;
    FileLogger::instance().log("StaffDemo.Main -- STAFF & PROJECTS initialized.");


    std::string DIRECTORY(staffDataDirectory);
    FileLogger::instance().log("StaffDemo.Main DIRECTORY loaded.");

    FileLogger::instance().log("StaffDemo::UI::Screens.start_screen render.");

    switch (auto _load {TUI::START_SCREEN(WIN_WIDTH, WIN_HEIGHT, DIRECTORY)}; _load) {
        case 'y':
            system("cls");
            TUI::Employees_LOAD_SCREEN(WIN_WIDTH, WIN_HEIGHT, DIRECTORY, STAFF, PROJECTS);
            break;
        case 'n':
            system("cls");

            break;
        default:
            std::cout << "ERROR" << std::endl;
            break;
    }

    system("pause");
    return EXIT_SUCCESS;
}