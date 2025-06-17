//
// Created by hid3h on 14.06.2025.
//

#include "ui/View/BaseScreenView.h"

namespace View {
    BaseScreenView::BaseScreenView(std::shared_ptr<ViewModel::BaseScreenViewModel> _vm, std::shared_ptr<SubView::SettingsSubView> settingsSubView) : BasicView(_vm), viewModel(_vm), SettingsScreen(settingsSubView) {

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

        stackedContainerScreens = Container::Stacked({
//            BaseScreen,
//            findEmployeeScreen,
            SettingsScreen
        });

        windowContainer = Container::Horizontal({
            LeftMainMenu,
            SettingsScreen
        });
        Add(windowContainer);
    }

    BaseScreenView::~BaseScreenView() {
        delete LeftMainMenuSelector;
    }

    void BaseScreenView::changeLeftMainMenuSelector(int newSelector) {
        if (*LeftMainMenuSelector == newSelector) {
            delete LeftMainMenuSelector;
            LeftMainMenuSelector = new int {newSelector};
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

        auto rightSceneFillScreens = SettingsScreen->Render();

        auto footer = hbox({
            text(StatusMessage),
            filler() | size(WIDTH, EQUAL, 10),
            text(StatusText) | size(WIDTH, EQUAL, 50), separator()
        }) | borderStyled(theme.bg_primary);

        return vbox({
            windowHeader | size(HEIGHT, EQUAL, 5),
            hbox({
//                leftMenu, rightSceneFill | flex
                leftMenu, rightSceneFillScreens | flex
            }),
            footer
        });
    }

//    void BaseScreenView::changeActiveSubScreen() {
//        switch (*LeftMainMenuSelector) {
//            case 0:
//                stackedContainerScreens->SetActiveChild(BaseScreen);
//                break;
//            case 1:
//                stackedContainerScreens->SetActiveChild(findEmployeeScreen);
//                break;
//            case 2:
//                stackedContainerScreens->SetActiveChild(SettingsScreen);
//        }
//    }

//    void BaseScreenView::initBaseScreen() {
//        auto bScreen = Renderer([]{
//            return vbox({
//                filler() | size(HEIGHT, EQUAL, 3),
//                hbox({text("Base Screen of StaffDemo") | hcenter}),
//                filler() | size(HEIGHT, EQUAL, 3),
//                hbox({text("Kzt18829d, 2025") | hcenter})
//            });
//        });
//        BaseScreen = bScreen;
//    }

//    void BaseScreenView::initSettingsScreen() {
//        const auto& theme = viewModel->getTheme();
//
//        auto currentThemeField = hbox({
//            text(viewModel->getTranslate("VIEW_BaseScreenView_SettingsScreen_CurrentThemeText") + "    "),
//            text(theme.name)
//        });
//
//        auto sScreen = Renderer([&](){
//            return vbox({
//
//            });
//        });
//        SettingsScreen = sScreen;
//    }

//    void BaseScreenView::initFindEmployeeScreen() {
//        auto fill = hbox({
//           text("FindEmployeeScreen")
//        });
//        auto FEScreen = Renderer([&]{
//            return vbox({fill});
//        });
//        findEmployeeScreen = FEScreen;
//    }
} // View