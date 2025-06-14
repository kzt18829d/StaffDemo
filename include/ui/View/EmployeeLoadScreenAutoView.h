//
// Created by hid3h on 09.06.2025.
//

#ifndef STAFFDEMO_EMPLOYEELOADSCREENAUTOVIEW_H
#define STAFFDEMO_EMPLOYEELOADSCREENAUTOVIEW_H
#include "BasicView.h"
#include "../ViewModel/EmployeeLoadScreenAutoViewModel.h"
#include "../../core/Usages.h"
#include "ftxui/dom/elements.hpp"
#include "fmt/core.h"


namespace View {

    class EmployeeLoadScreenAutoView : public BasicView {
    private:
        std::shared_ptr<ViewModel::EmployeeLoadScreenAutoViewModel> viewModel;
        Message statusMessage;
        TextLabel gaugeProcentString;

        std::function<void()> navigateToBaseWindowFunction;

        ftxui::Element loadingGauge;
        ftxui::Element loadEmployeesLog;

        ftxui::Component navigateToBaseWindowButton;

        ftxui::Component windowContainer;

        void updateCurrentGaugeProcent();
        void addLogLineToLoadEmployeesLog();
        void updateCurrentGaugeProcentString();

//        boost::signals2::signal<void()> saveAndGoBaseWindowConnection;
        boost::signals2::connection updateLoadedEmployeeScreenLogConnection;
        boost::signals2::connection updateGaugeConnection;

    public:
        explicit EmployeeLoadScreenAutoView(std::shared_ptr<ViewModel::EmployeeLoadScreenAutoViewModel> _viewModel);
        ftxui::Element Render() override;

    };

} // View

#endif //STAFFDEMO_EMPLOYEELOADSCREENAUTOVIEW_H
