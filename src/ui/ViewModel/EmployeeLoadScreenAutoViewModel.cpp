//
// Created by hid3h on 09.06.2025.
//

#include "ui/ViewModel/EmployeeLoadScreenAutoViewModel.h"

namespace ViewModel {
    EmployeeLoadScreenAutoViewModel::EmployeeLoadScreenAutoViewModel(std::shared_ptr<Core::AppSettings> sharedPtr) : BasicViewModel(sharedPtr) {
        loadedEmployeesCount = std::make_unique<Counter>(0);
        loadedEmployeesPotentialCount = std::make_unique<Counter>(0);
        SuccessLoadEmployees = std::make_shared<bool>(true);

        currentGaugeLine = std::make_shared<gaugeCounter>(0.0);

//        loadedEmployeeSignalConnection =
    }

    Counter *EmployeeLoadScreenAutoViewModel::getLoadedEmployeesCount() const {
        return loadedEmployeesCount.get();
    }

    Counter *EmployeeLoadScreenAutoViewModel::getLoadedEmployeesPotentialCount() const {
        return loadedEmployeesPotentialCount.get();
    }

    bool *EmployeeLoadScreenAutoViewModel::getSuccessLoadEmployees() const {
        return SuccessLoadEmployees.get();
    }

    gaugeCounter EmployeeLoadScreenAutoViewModel::getCurrentGaugeLine() const {
        return *currentGaugeLine;
    }

    std::queue<Text> EmployeeLoadScreenAutoViewModel::getLoadedEmployeeScreenLog_all() const {
        return loadedEmployeeScreenLog;
    }

    std::queue<Text> EmployeeLoadScreenAutoViewModel::getLoadedEmployeeScreenLog_last_q() const {
        std::queue<Text> tmp;
        tmp.push(loadedEmployeeScreenLog.back());
        return tmp;
    }

    Text EmployeeLoadScreenAutoViewModel::getLoadedEmployeeScreenLog_last_t() const{
        return loadedEmployeeScreenLog.back();
    }

    void EmployeeLoadScreenAutoViewModel::addCurrentGaugeLine(gaugeCounter addGauge) {
        if (*currentGaugeLine >= maxGaugeLine) {
        }
        else if (*currentGaugeLine < maxGaugeLine && addGauge < maxGaugeLine) {
            if (addGauge <= maxGaugeLine - *currentGaugeLine) *currentGaugeLine += addGauge;
            else *currentGaugeLine = maxGaugeLine;
        }
        updateGaugeSignal(*currentGaugeLine);
   }

    void EmployeeLoadScreenAutoViewModel::addLoadedEmployeeScreenLogLine(Text& text) {
        loadedEmployeeScreenLog.push(std::move(text));
        updateLoadedEmployeeScreenLogSignal(text);
    }
} // ViewModel