//
// Created by hid3h on 08.06.2025.
//

#include "StartScreenView.h"

namespace View {

    StartScreenView::StartScreenView(const std::shared_ptr<ViewModel::StartScreenViewModel>& _viewModel) : BasicView(_viewModel), viewModel(std::move(_viewModel)) {
        checkBoxMessage         = viewModel->getCheckBoxMessage();
        statusMessage           = viewModel->getStatusMessage();

        StaffDirectoryInputOption.multiline = false;

        staffDirectoryInput     = ftxui::Input(viewModel->setStaffDirectory(),  StaffDirectoryInputOption);
        autoLoadCheckBox        = ftxui::Checkbox(viewModel->getCheckBoxMessage(), viewModel->getAutoLoadEmployeesCheckBox_bool());

        //add Translation Manager
        defaultSettingsButton   = ftxui::Button("Use Default", [&, this]{ viewModel->useDefaultSettings(); });
        customSettingsButton    = ftxui::Button("Use Current", [&, this]{ viewModel->useCustomSettings(); });

        windowContainer         = ftxui::Container::Vertical({
            staffDirectoryInput,
            autoLoadCheckBox,
            customSettingsButton, defaultSettingsButton
        });

        statusMessageChangedConnection = viewModel->statusMessageChangedSignal.connect([this](const Message&){
            statusMessage = viewModel->getStatusMessage();
            this->reRender();
        });

        this->Add(windowContainer);
    }

    ftxui::Element StartScreenView::Render() {
        const auto& theme = viewModel->getTheme();

        auto windowHeader = ftxui::hbox({
            ftxui::filler(),
            ftxui::text(/*Translate::instance().dict().at(*/"TITLE_START_SCREEN")/*)*/ | ftxui::center | ftxui::bold,
            ftxui::filler()
        }) | ftxui::bgcolor(theme.bg_primary) | ftxui::color(theme.text_window_header) | ftxui::borderStyled(theme.border_window_header);

        auto staffPath = hbox({
            text("  Staff Directory:  "), staffDirectoryInput->Render(), text("  ")
        }) | size(WIDTH, EQUAL, 50) | ftxui::borderStyled(theme.border_primary);

        auto buttons = hbox({
            customSettingsButton->Render()  | theme.button_style | (customSettingsButton->Focused() ? theme.button_focused : nothing)  | size(WIDTH, EQUAL, 20),
            defaultSettingsButton->Render() | theme.button_style | (defaultSettingsButton->Focused() ? theme.button_focused : nothing) | size(WIDTH, EQUAL, 20)
        });

        return vbox({
            windowHeader | size(HEIGHT, EQUAL, 5),
            vbox({
                filler() | size(HEIGHT, EQUAL, 6),
                hbox({staffPath}) | hcenter,
                filler() | size(HEIGHT, EQUAL, 6),
                vbox({
                    hbox({autoLoadCheckBox->Render()}) | align_right,
                        buttons | align_right
                })
            })
        }) | bgcolor(theme.bg_primary) | color(theme.text_primary);
    }

    void StartScreenView::updateStatusMessage(Message &newMessage) {
        viewModel->updateStatusMessage(newMessage);
    }
} // View