//
// Created by hid3h on 09.06.2025.
//

#include "ui/View/EmployeeLoadScreenAutoView.h"

namespace View {

    EmployeeLoadScreenAutoView::EmployeeLoadScreenAutoView(
            std::shared_ptr<ViewModel::EmployeeLoadScreenAutoViewModel> _viewModel) : BasicView(_viewModel), viewModel(_viewModel) {

        gaugeProcentString = std::to_string(static_cast<int>(viewModel->getCurrentGaugeLine())) + "%";

        loadingGauge = ftxui::gaugeRight(0.0);
        loadEmployeesLog = ftxui::paragraphAlignLeft("log");

        navigateToBaseWindowButton = ftxui::Button(fmt::format("{:^{}}", viewModel->getTranslate("VIEWMODEL_EmployeeLoadScreenAuto_navigateToBaseWindowButton"), 38), [&]() {
            if (*viewModel->getSuccessLoadEmployees() == true) viewModel->saveAndGoBaseWindowSignal(WindowType::BASE_WINDOW); // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            else return void();
        });

        windowContainer = ftxui::Container::Vertical({
            navigateToBaseWindowButton
        });

        Add(windowContainer);
//        Add(navigateToBaseWindowButton);
    }

    ftxui::Element EmployeeLoadScreenAutoView::Render() {
        const auto& theme = viewModel->getTheme();

        updateCurrentGaugeProcent();
        updateCurrentGaugeProcentString();

        auto loadingGaugeRender = vbox({
            loadingGauge | color(theme.text_primary) | size(WIDTH, EQUAL, 60) | borderHeavy,
            text(gaugeProcentString) | hcenter | color(theme.text_primary),
            text(statusMessage) | hcenter | color(theme.text_primary)
        });
        auto windowHeader = ftxui::hbox({
            ftxui::filler(),
            ftxui::text(fmt::format("{:^}", viewModel->getTranslate("TITLE_F1"))) | ftxui::center | ftxui::bold,
            ftxui::filler()
        }) | ftxui::bgcolor(theme.bg_primary) | ftxui::color(theme.text_window_header) | ftxui::borderStyled(theme.border_window_header);

        auto loadEmployeesLogRender = vbox({
            vbox({text("EXAMPLE")}) | hcenter | vcenter
        }) | borderStyled(theme.border_primary) | size (WIDTH, EQUAL, 80) | size(HEIGHT, EQUAL, 8);

        auto buttons = ftxui::hbox({
           navigateToBaseWindowButton->Render() | (navigateToBaseWindowButton->Focused() ? ftxui::inverted : ftxui::nothing)
        });

        return vbox({
            windowHeader | size(HEIGHT, EQUAL, 5),
            vbox({
                filler() | size(HEIGHT, EQUAL, 2),
                loadingGaugeRender | hcenter,
                filler() | size(HEIGHT, EQUAL, 1),
                loadEmployeesLogRender | hcenter,
                filler() | size(HEIGHT, EQUAL, 2),
                hbox({buttons}) | align_right
            }) | size(HEIGHT, EQUAL, 22),
            hbox({}) | borderStyled(theme.border_window)| size(HEIGHT, EQUAL, 3)
        }) | bgcolor(theme.bg_primary) | color(theme.text_primary);
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