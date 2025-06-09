//
// Created by hid3h on 09.06.2025.
//

#include "EmployeeLoadScreenAutoView.h"

namespace View {


    EmployeeLoadScreenAutoView::EmployeeLoadScreenAutoView(
            std::shared_ptr<ViewModel::EmployeeLoadScreenAutoViewModel> _viewModel) : BasicView(_viewModel), viewModel(_viewModel) {

        navigateToBaseWindowFunction = [&]() {
            if (viewModel->getSuccessLoadEmployees()) viewModel->saveAndGoBaseWindowSignal(WindowType::BASE_WINDOW);
        };

        gaugeProcentString = std::to_string(viewModel->getCurrentGaugeLine());

        loadingGauge = ftxui::gaugeRight(0.0);
        loadEmployeesLog = ftxui::paragraphAlignLeft("");

        navigateToBaseWindowButton = ftxui::Button(viewModel->getTranslate("VIEWMODEL_EmployeeLoadScreenAuto_navigateToBaseWindowButton", true), navigateToBaseWindowFunction);

        windowContainer = ftxui::Container::Vertical({
            navigateToBaseWindowButton
        });

        Add(windowContainer);
    }

    ftxui::Element EmployeeLoadScreenAutoView::Render() {
        const auto& theme = viewModel->getTheme();

        auto loadingGaugeRender = vbox({
            loadingGauge | color(theme.text_primary) | hcenter,
            text(statusMessage) | hcenter | color(theme.text_primary)
        });
        auto windowHeader = ftxui::hbox({
            ftxui::filler(),
            ftxui::text(/*Translate::instance().dict().at(*/"TITLE_START_SCREEN")/*)*/ | ftxui::center | ftxui::bold,
            ftxui::filler()
        }) | ftxui::bgcolor(theme.bg_primary) | ftxui::color(theme.text_window_header) | ftxui::borderStyled(theme.border_window_header);

        auto loadEmployeesLogRender = vbox({

        }) | borderStyled(theme.border_primary);

        auto buttons = ftxui::hbox({
           navigateToBaseWindowButton->Render() | color(theme.text_primary) | bgcolor(theme.bg_primary)
        });

        return vbox({
            windowHeader | size(HEIGHT, EQUAL, 5),
            vbox({
                filler() | size(HEIGHT, EQUAL, 5),
                loadingGaugeRender | hcenter,
                filler() | size(HEIGHT, EQUAL, 5),
                loadEmployeesLogRender | hcenter,
                filler() | size(HEIGHT, EQUAL, 5)
            }) | size(HEIGHT, EQUAL, 22),
            hbox({}) | borderStyled(theme.border_window)| size(HEIGHT, EQUAL, 3)
        });
    }

    void EmployeeLoadScreenAutoView::updateCurrentGaugeProcent() {
        loadingGauge = ftxui::gaugeRight(viewModel->getCurrentGaugeLine());
    }

    void EmployeeLoadScreenAutoView::addLogLineToLoadEmployeesLog() {
    }

    void EmployeeLoadScreenAutoView::updateCurrentGaugeProcentString() {
        gaugeProcentString = std::to_string(viewModel->getCurrentGaugeLine());
    }

} // View