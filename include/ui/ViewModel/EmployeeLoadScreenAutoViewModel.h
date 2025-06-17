#ifndef STAFFDEMO_EMPLOYEELOADSCREENAUTOVIEWMODEL_H
#define STAFFDEMO_EMPLOYEELOADSCREENAUTOVIEWMODEL_H
#include "BasicViewModel.h"
#include "../../core/AppSetting.h"
#include "../../core/Usages.h"
#include "queue"
#include "../../core/ScreensENUM.h"
namespace ViewModel {

    class EmployeeLoadScreenAutoViewModel : public BasicViewModel {
    private:
        std::unique_ptr<Counter> loadedEmployeesCount;
        std::unique_ptr<Counter> loadedEmployeesPotentialCount;
        std::shared_ptr<bool> SuccessLoadEmployees;
        std::queue<Text> loadedEmployeeScreenLog;

        const gaugeCounter maxGaugeLine {1};
        std::shared_ptr<gaugeCounter> currentGaugeLine;


        boost::signals2::connection loadedEmployeeSignalConnection;

    public:
        explicit EmployeeLoadScreenAutoViewModel(std::shared_ptr<Core::AppSettings> sharedPtr);

        Counter* getLoadedEmployeesCount() const;
        Counter* getLoadedEmployeesPotentialCount() const;
        bool* getSuccessLoadEmployees() const;
        gaugeCounter getCurrentGaugeLine() const;
        std::queue<Text> getLoadedEmployeeScreenLog_all() const;
        std::queue<Text> getLoadedEmployeeScreenLog_last_q() const;
        Text getLoadedEmployeeScreenLog_last_t() const;



        void addCurrentGaugeLine(gaugeCounter addGauge);
        void addLoadedEmployeeScreenLogLine(Text& text);

        boost::signals2::signal<void(WindowType nextScreen)> saveAndGoBaseWindowSignal;
        boost::signals2::signal<void(Text&)> updateLoadedEmployeeScreenLogSignal;
        boost::signals2::signal<void(gaugeCounter&)> updateGaugeSignal;
    };

} // ViewModel

#endif //STAFFDEMO_EMPLOYEELOADSCREENAUTOVIEWMODEL_H
