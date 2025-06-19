//
// Created by hid3h on 14.06.2025.
//

#include "ui/View/BaseScreenView.h"

namespace View {
    BaseScreenView::BaseScreenView(std::shared_ptr<ViewModel::BaseScreenViewModel> _vm, std::shared_ptr<SubView::BaseSubScreenView> baseSubView, std::shared_ptr<SubView::SettingsSubView> settingsSubView ) : BasicView(_vm), viewModel(_vm), BaseScreen(baseSubView), SettingsScreen(settingsSubView) {
        LeftMainMenuSelector = new int(0);
        currentScreen = new int(0);
        StatusMessage = viewModel->getTranslate("VIEW_BaseScreenView_Footer_State");
        toBaseScreenButton = Button(fmt::format("{:^{}}", viewModel->getTranslate("VIEW_BaseScreenView_toBaseScreenButton"), 22), [&]{
            changeLeftMainMenuSelector(0);
        });

        toFindEmployeeScreenButton = Button(fmt::format("{:^{}}", viewModel->getTranslate("VIEW_BaseScreenView_toFindEmployeeScreenButton"), 22), [&]{
            changeLeftMainMenuSelector(1);
        });
        toSettingsScreenButton = Button(fmt::format("{:^{}}", viewModel->getTranslate("VIEW_BaseScreenView_toSettingsScreenButton"), 22), [&]{
            changeLeftMainMenuSelector(2);
        });
        MainSaveButton = Button(fmt::format("{:^{}}", viewModel->getTranslate("VIEW_BaseScreenView_MainSaveButton"), 22), [&] {
            changeSaveMessage(viewModel->getTranslate("VIEW_BaseScreenView_SaveMessage"));
            viewModel->ViewUpdateSignal();
        });
        ExitButton = Button(fmt::format("{:^{}}", viewModel->getTranslate("VIEW_BaseScreenView_ExitButton"), 22), [&]{
            viewModel->exitSignal();
        });


        LeftMainMenu = Container::Vertical({toBaseScreenButton, toFindEmployeeScreenButton, toSettingsScreenButton, MainSaveButton, ExitButton},
                                           LeftMainMenuSelector);

//        initBaseScreen();
//        initSettingsScreen();
//        initFindEmployeeScreen();

        stackedContainerScreens = SettingsScreen;

        windowContainer = Container::Horizontal({
            LeftMainMenu,
            SettingsScreen
        });
        Add(windowContainer);
        Add(stackedContainerScreens);
    }

    BaseScreenView::~BaseScreenView() {
        delete LeftMainMenuSelector;
        delete currentScreen;
    }

    void BaseScreenView::changeLeftMainMenuSelector(int newSelector) {

        delete LeftMainMenuSelector;
        LeftMainMenuSelector = new int {newSelector};

        switch (*LeftMainMenuSelector) {
            case 0:
                toBaseScreenButton->TakeFocus();
                break;
            case 2:
                toSettingsScreenButton->TakeFocus();
                break;
            case 1:
                toFindEmployeeScreenButton->TakeFocus();
                break;
            default:
                break;
        }
    }

    void BaseScreenView::changeSaveMessage(Text newMessage) {
        saveMessage = std::move(newMessage);
    }

    ftxui::Element BaseScreenView::Render() {
        auto theme = viewModel->getTheme();

        auto windowHeader = ftxui::hbox({
            ftxui::filler(),
            ftxui::text(fmt::format("{:^{}}",viewModel->getTranslate("TITLE_F1"), 34)) | ftxui::center | ftxui::bold,
            ftxui::filler()
        }) | ftxui::bgcolor(theme.bg_primary) | ftxui::color(theme.text_window_header) | ftxui::borderStyled(theme.border_window_header);

        setHoveredStatusToScreenSwitchButtons();

        auto leftMenu = vbox({
            text(fmt::format("{:^{}}", viewModel->getTranslate("TITLE1"), 24)) | center | bold,
            text(fmt::format("{:^{}}", viewModel->getTranslate("VIEW_BaseScreenView_Text_MainMenu"), 24)),
            separatorDouble(),
            filler(),
            toBaseScreenButton->Render(),
            toFindEmployeeScreenButton->Render(),
            toSettingsScreenButton->Render(),
            filler() | size(HEIGHT, EQUAL, 1),
            hbox({ text(fmt::format("{:^{}}", saveMessage, 24)) | center }),
            MainSaveButton->Render(),
            ExitButton->Render()
        }) | size(WIDTH, EQUAL, 24) | bgcolor(theme.bg_primary) | color(theme.text_accent) | borderStyled(theme.border_window);

        auto rightSceneFill = vbox({
            text("Base Window") | hcenter | vcenter
        }) | borderStyled(theme.border_primary);

        auto rightSceneFillScreens = stackedContainerScreens->ActiveChild()->Render();

        auto footer = hbox({
            text(StatusMessage),
            filler() | size(WIDTH, EQUAL, 10),
            text(StatusText) | size(WIDTH, EQUAL, 50), separator()
        }) | borderStyled(theme.border_primary);

        return vbox({
            windowHeader | size(HEIGHT, EQUAL, 5),
            hbox({
//                leftMenu, rightSceneFill | flex
                leftMenu, getActiveSubScreen()->Render() | flex
            }),
            footer
        }) | bgcolor(theme.bg_primary);
    }

    ftxui::Component BaseScreenView::getActiveSubScreen() {
        switch (*currentScreen) {
            case 0:
                return BaseScreen;
            case 1:
                return findEmployeeScreen;
            case 2:
                return SettingsScreen;
        }
        return nullptr;
    }

    void BaseScreenView::setHoveredStatusToScreenSwitchButtons() {
        switch (*currentScreen) {
            case 0:
                toBaseScreenButton->TakeFocus();
                break;
            case 1:
                toFindEmployeeScreenButton->TakeFocus();
                break;
            case 2:
                toSettingsScreenButton->TakeFocus();
                break;
        }
    }

} // View