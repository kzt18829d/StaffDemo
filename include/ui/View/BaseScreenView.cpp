//
// Created by hid3h on 14.06.2025.
//

#include "BaseScreenView.h"

namespace View {
    BaseScreenView::BaseScreenView(std::shared_ptr<ViewModel::BaseScreenViewModel> _vm) : BasicView(_vm), viewModel(_vm){
        toBaseScreenButton = Button(fmt::format("{:^{}}", viewModel->getTranslate("VIEW_BaseScreenView_toBaseScreenButton"), 20), [&]{
            changeLeftMainMenuSelector(1);
        });

        toFindEmployeeScreenButton = Button(fmt::format("{:^{}}", viewModel->getTranslate("VIEW_BaseScreenView_toFindEmployeeScreenButton"), 20), [&]{
            changeLeftMainMenuSelector(2);
        });
        toSettingsScreenButton = Button(fmt::format("{:^{}}", viewModel->getTranslate("VIEW_BaseScreenView_toSettingsScreenButton"), 20), [&]{
            changeLeftMainMenuSelector(3);
        });
        MainSaveButton = Button(fmt::format("{:^{}}", viewModel->getTranslate("VIEW_BaseScreenView_MainSaveButton"), 20), [&] {
            changeSaveMessage(viewModel->getTranslate("VIEW_BaseScreenView_SaveMessage"));
            viewModel->ViewUpdateSignal();
        });
        ExitButton = Button(fmt::format("{:^{}}", viewModel->getTranslate("BaseScreenView_ExitButton"), 20), [&]{
            viewModel->exitSignal();
        });


        LeftMainMenu = Container::Vertical({toBaseScreenButton, toFindEmployeeScreenButton, toSettingsScreenButton, MainSaveButton, ExitButton},
                                           LeftMainMenuSelector);

        stackedContainerScreens = Container::Stacked({
//            BaseScreen,
//            findEmployeeScreen,
//            SettingsScreen
        });

        windowContainer = Container::Horizontal({
            LeftMainMenu
//            stackedContainerScreens,
        });
        Add(windowContainer);
    }

    BaseScreenView::~BaseScreenView() {
        delete LeftMainMenuSelector;
    }

    ftxui::Element BaseScreenView::Render() {
        auto menuRender = vbox({});
        return vbox({text("123214")});
    }

    void BaseScreenView::changeLeftMainMenuSelector(int newSelector) {
        if (*LeftMainMenuSelector != newSelector) {
            delete LeftMainMenuSelector;
            LeftMainMenuSelector = new int {newSelector};
        }
    }

    void BaseScreenView::changeSaveMessage(Text newMessage) {
        saveMessage = newMessage;
    }
} // View