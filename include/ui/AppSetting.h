#ifndef STAFFDEMO_APPSETTING_H
#define STAFFDEMO_APPSETTING_H
#include "string"
#include "algorithm"
#include "ctime"
#include "../staff/IEmployee.h"
#include "../interaface/IStaffRepository.h"
#include "../interaface/IProjectRepository.h"
#include "../interaface/ISPStorageProvider.h"

inline std::string getTime() {
    const time_t now = time(nullptr);
    std::string time_str = ctime(&now);

    if (!time_str.empty() && time_str.back() == '\n') {
        time_str.pop_back();
    }

    std::replace(time_str.begin(), time_str.end(), ' ', '_');
    std::replace(time_str.begin(), time_str.end(), ':', '-');

    return time_str;
}


class AppSettings {
public:
#ifdef NDEBUG
    std::string localizationDataDirectory = "LNG.json";
    std::stringstaffDataDirectory = "Staff_Data.csv";
    std::string logFileDirectory = "logs/log-" + getTime();
    std::string themeDataDirectory = "./Data_local/themes.json";
#else
    std::string localizationDataDirectory = "./Data_local/newLangs.json";
    std::string staffDataDirectory = "./Data_local/Staff_Data.csv";
    std::string logFileDirectory = "./Data_local/logs/log-" + getTime();
    std::string themeDataDirectory = "./Data_local/themes.json";
#endif


};

#endif //STAFFDEMO_APPSETTING_H
