#ifndef STAFFDEMO_SETTINGSSUBVIEW_H
#define STAFFDEMO_SETTINGSSUBVIEW_H
#include "../BasicView.h"
#include "../../ViewModel/BaseScreenSubViewModel/SettingsSubViewModel.h"

namespace View::SubView {

    class SettingsSubView : public BasicView {
        std::shared_ptr<ViewModel::SubViewModel::SettingsSubViewModel> subViewModel;

        int bord = 30;
        int interblockBord = 15;
        bool* canHoverableThemeButton = new bool{false};
        bool* checkBoxSaver = new bool{false};
        Text ThemeTextWindow;
        Text themeText, currentThemeText;
        Text changeThemeText;
        ftxui::Component ThemesDropdown;
        ftxui::Component CreateThemeButton;

        Text LanguageTextWindow;
        Text languageText, currentLanguageText;
        Text changeLanguageText;
        ftxui::Component LanguagesDropdown;

        Text RepositoryTextWindow;
        Text repositoryWarning;
        Text createRepositoryCheckboxText;
        ftxui::Component saveRepositoryButton;
        ftxui::Component createNewRepositoryButton;
        ftxui::Component createRepositoryCheckBox;

        ftxui::Component windowContainer;


    public:
        SettingsSubView(std::shared_ptr<ViewModel::SubViewModel::SettingsSubViewModel> sVM);
        ~SettingsSubView();

        ftxui::Element Render() override;
    };

} // SubView
// View

#endif //STAFFDEMO_SETTINGSSUBVIEW_H
