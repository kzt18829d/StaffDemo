#ifndef STAFFDEMO_BASESCREENVIEW_H
#define STAFFDEMO_BASESCREENVIEW_H
#include "BasicView.h"
#include "../ViewModel/BaseScreenViewModel.h"
#include "fmt/core.h"
#include "BaseScreenSubViews/SettingsSubView.h"
#include "memory"

namespace View {

    class BaseScreenView : public BasicView {
    private:
        std::shared_ptr<ViewModel::BaseScreenViewModel> viewModel;

        int* LeftMainMenuSelector = new int{0};
        TextLabel saveMessage;
        TextLabel StatusText;
        TextLabel StatusMessage;


        std::function<void()> saveFunction;
        std::function<void()> exitFunction;

        ftxui::Component toBaseScreenButton;
        ftxui::Component toSettingsScreenButton;
        ftxui::Component toFindEmployeeScreenButton;
        ftxui::Component MainSaveButton;
        ftxui::Component ExitButton;

        ftxui::Component BaseScreen;
        ftxui::Component SettingsScreen;
//        ftxui::Component SettingsScreen;

        ftxui::Component findEmployeeScreen;

        std::vector<std::string> LeftMainMenuEntries;

        ftxui::Component LeftMainMenu;

        ftxui::Component stackedContainerScreens;

        ftxui::Component windowContainer;

        void changeLeftMainMenuSelector(int newSelector);
        void changeSaveMessage(Text newMessage);

//        void initBaseScreen();
//        void initSettingsScreen();
//        void initFindEmployeeScreen();

//        void changeActiveSubScreen();

    public:
        explicit BaseScreenView(std::shared_ptr<ViewModel::BaseScreenViewModel> _vm, std::shared_ptr<SubView::SettingsSubView> settingsSubView);
        ~BaseScreenView() override;

        ftxui::Element Render() override;
    };

} // View

#endif //STAFFDEMO_BASESCREENVIEW_H
