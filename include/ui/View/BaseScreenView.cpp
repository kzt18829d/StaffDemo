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


        LeftMainMenu = Container::Vertical({toBaseScreenButton, toFindEmployeeScreenButton, toSettingsScreenButton, MainSaveButton, ExitButton},
                                           LeftMainMenuSelector);

        stackedContainerScreens = Container::Stacked({
            BaseScreen,
            findEmployeeScreen,
            SettingsScreen
        });

        windowContainer = Container::Horizontal({
            LeftMainMenu,
            stackedContainerScreens,
        });
    }

    BaseScreenView::~BaseScreenView() {

    }

    ftxui::Element BaseScreenView::Render() {
        return BasicView::Render();
    }

    void BaseScreenView::changeLeftMainMenuSelector(int newSelector) {
        if (*LeftMainMenuSelector != newSelector) {
            delete LeftMainMenuSelector;
            LeftMainMenuSelector = new int {newSelector};
        }
    }
} // View