//
// Created by hid3h on 14.06.2025.
//

#ifndef STAFFDEMO_BASESCREENVIEW_H
#define STAFFDEMO_BASESCREENVIEW_H
#include "BasicView.h"
#include "../ViewModel/BaseScreenViewModel.h"
#include "fmt/core.h"

namespace View {

    class BaseScreenView : public BasicView {
    private:
        std::shared_ptr<ViewModel::BaseScreenViewModel> viewModel;

        int* LeftMainMenuSelector = new int{0};

        std::function<void()> saveFunction;
        std::function<void()> exitFunction;

        ftxui::Component toBaseScreenButton;
        ftxui::Component toSettingsScreenButton;
        ftxui::Component toFindEmployeeScreenButton;
        ftxui::Component MainSaveButton;
        ftxui::Component ExitButton;

        ftxui::Component BaseScreen;
        ftxui::Component SettingsScreen;
        ftxui::Component findEmployeeScreen;

        std::vector<std::string> LeftMainMenuEntries;

        ftxui::Component LeftMainMenu;

        ftxui::Component stackedContainerScreens;

        ftxui::Component windowContainer;

        void changeLeftMainMenuSelector(int newSelector);

    public:
        BaseScreenView(std::shared_ptr<ViewModel::BaseScreenViewModel> _vm);
        ~BaseScreenView();

        ftxui::Element Render() override;
    };

} // View

#endif //STAFFDEMO_BASESCREENVIEW_H
