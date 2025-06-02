//
// Created by hid3h on 29.05.2025.
//

#include <utility>

#include "../../../include/ui/View/StartScreenView.h"

namespace View {
    void StartScreenView::ThemeChanged(const Theme &newTheme) {
        void();
    }

    StartScreenView::StartScreenView(std::shared_ptr<Model::StartScreenViewModel> viewModel_) : StaffDemo::UI::ViewBase(viewModel), viewModel(std::move(viewModel_)) {

        ftxui::InputOption staffDirectoryInputFieldOption;
        std::shared_ptr<ftxui::ButtonOption> applyCustomSettingsButtonOption;
        std::shared_ptr<ftxui::ButtonOption> applyDefaultSettingsButtonOption;

        staffDirectoryInputFieldOption.on_change = [&] {
            viewModel->setStaffDir();
        };
        staffDirectoryInputFieldOption.multiline = false;

        applyDefaultSettingsButtonOption->on_click = [&]{
            viewModel->DefaultSettings();
            viewModel->applySettingSignal();
        };
        applyDefaultSettingsButtonOption->label = Translate::instance().dict().at("BUTTON.StartScreen.ApplyDefault");

        applyCustomSettingsButtonOption->on_click = [&] {
            if (activeCustomSettingsButton) {
                viewModel->ApplySettings();
                viewModel->applySettingSignal;
            }
        };
        applyCustomSettingsButtonOption->label = Translate::instance().dict().at("BUTTON.StartScreen.ApplyCustom");

        applyDefaultSettingsButton = ftxui::Button(*applyDefaultSettingsButtonOption);
        applyCustomSettingsButton = ftxui::Button(*applyCustomSettingsButtonOption);

        windowContainer = ftxui::Container::Vertical({
            staffDirectoryInputField,
            ftxui::Container::Horizontal({applyCustomSettingsButton, applyDefaultSettingsButton})
        });

        statusSignalConnection = viewModel->statusMessageChangedSignal.connect([this](const std::string&){
            viewModel->updateStatusMessage(statusMessage_);
        });

        statusMessage_ = viewModel->getStatusMessage();

    }

    ftxui::Element StartScreenView::Render() {
        using namespace ftxui;
        const auto& theme = getTheme();

        auto windowHeader = ftxui::hbox({
                                                ftxui::filler(),
                                                ftxui::text(Translate::instance().dict().at("TITLE_START_SCREEN")) | ftxui::center | ftxui::bold,
                                                ftxui::filler()
                                        }) | ftxui::borderHeavy | ftxui::bgcolor(theme.bg_secondary) | ftxui::color(theme.text_window_header);

        auto staffPath = hbox({
            text("Staff Path: "), staffDirectoryInputField->Render()
        }) | size(WIDTH, EQUAL, 40);

        auto buttonsElements = hbox({
            applyCustomSettingsButton->Render() | theme.button_style | (applyCustomSettingsButton->Focused() ? theme.button_focused : nothing) | size(WIDTH, EQUAL, 14),
            applyDefaultSettingsButton->Render() | theme.button_style | (applyCustomSettingsButton->Focused() ? theme.button_focused : nothing) | size(WIDTH, EQUAL, 14)
        }) | align_right ;


        return vbox({
            windowHeader | size(HEIGHT, EQUAL, 5),
            vbox({
                filler() | size(HEIGHT, EQUAL, 6),
                hbox({staffPath | hcenter}),
                filler() | size(HEIGHT, EQUAL, 10),
                buttonsElements
            }) | size(HEIGHT, EQUAL, 23)
        });
    }

    void StartScreenView::updateStatusMessage(const std::string &newMessage) {
        statusMessage_ = newMessage;
        reRenderRequestSignal();
    }

} // View