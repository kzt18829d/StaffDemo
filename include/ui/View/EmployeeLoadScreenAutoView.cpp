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

        gaugeProcentString = std::to_string(static_cast<int>(viewModel->getCurrentGaugeLine())) + "%";

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

//        updateCurrentGaugeProcent();
//        updateCurrentGaugeProcentString();

        auto loadingGaugeRender = vbox({
            loadingGauge | color(theme.text_primary) | size(WIDTH, EQUAL, 60) | borderHeavy,
            text(gaugeProcentString) | hcenter | color(theme.text_primary),
            text(statusMessage) | hcenter | color(theme.text_primary)
        });
        auto windowHeader = ftxui::hbox({
            ftxui::filler(),
            ftxui::text(/*Translate::instance().dict().at(*/"TITLE_START_SCREEN")/*)*/ | ftxui::center | ftxui::bold,
            ftxui::filler()
        }) | ftxui::bgcolor(theme.bg_primary) | ftxui::color(theme.text_window_header) | ftxui::borderStyled(theme.border_window_header);

        auto loadEmployeesLogRender = vbox({
            vbox({text("EXAMPLE")}) | hcenter | vcenter
        }) | borderStyled(theme.border_primary) | size (WIDTH, EQUAL, 80) | size(HEIGHT, EQUAL, 8);

        auto buttons = ftxui::hbox({
           navigateToBaseWindowButton->Render() | color(theme.text_primary) | bgcolor(theme.bg_primary) | theme.button_style | (navigateToBaseWindowButton->Focused() ? theme.button_focused : nothing)
        });

        return vbox({
            windowHeader | size(HEIGHT, EQUAL, 5),
            vbox({
                filler() | size(HEIGHT, EQUAL, 4),
                loadingGaugeRender | hcenter,
                filler() | size(HEIGHT, EQUAL, 1),
                loadEmployeesLogRender | hcenter,
                filler() | size(HEIGHT, EQUAL, 1),
                buttons | align_right
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
        gaugeProcentString = std::to_string(static_cast<int>(viewModel->getCurrentGaugeLine() * 100)) + "%";
    }

} // View