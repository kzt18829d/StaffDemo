//
// Created by hid3h on 29.05.2025.
//

#ifndef STAFFDEMO_STARTSCREENVIEW_H
#define STAFFDEMO_STARTSCREENVIEW_H
#include "ViewBase.h"
#include "ftxui/component/component.hpp"
#include "../ViewModel/StartScreenViewModel.h"
#include "../../utils/TranslationManager.h"
#include "memory"
#include "../../core/Signal2.h"
#include "string"
using Translate = StaffDemo::Utils::TranslationManager;
//using Translate = StaffDemo::Utils::TranslationManager::instance().dict().contains(key) ? StaffDemo::Utils::TranslationManager::instance().dict.at(key) : std::string(key);
namespace View {

class StartScreenView : public StaffDemo::UI::ViewBase {
    private:
        std::shared_ptr<Model::StartScreenViewModel> viewModel;
        ftxui::Component staffDirectoryInputField;
        ftxui::Component applyCustomSettingsButton;
        ftxui::Component applyDefaultSettingsButton;

        ftxui::Component windowContainer;

        std::string statusMessage_;

        std::shared_ptr<bool> activeDefaultSettingsButton = std::make_shared<bool>(true);
        std::shared_ptr<bool> activeCustomSettingsButton = std::make_shared<bool>(false);

        StaffDemo::Core::Connection<const std::string&> statusSignalConnection;
        StaffDemo::Core::Signal<> reRenderRequestSignal;
        void updateStatusMessage(const std::string& newMessage);

    protected:
        void ThemeChanged(const Theme& newTheme);
    public:
        StartScreenView(std::shared_ptr<Model::StartScreenViewModel> viewModel_);
        ftxui::Element Render() override;

    };

} // View

#endif //STAFFDEMO_STARTSCREENVIEW_H
