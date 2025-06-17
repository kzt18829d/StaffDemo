#ifndef STAFFDEMO_SETTINGSSUBVIEW_H
#define STAFFDEMO_SETTINGSSUBVIEW_H
#include "../BasicView.h"
#include "../../ViewModel/BaseScreenSubViewModel/SettingsSubViewModel.h"
#include "fmt/core.h"

namespace View::SubView {

    class SettingsSubView : public BasicView {
        std::shared_ptr<ViewModel::SubViewModel::SettingsSubViewModel> subViewModel;

        int bord = 15;
        int interblockBord = 15;
        bool* canHoverableThemeButton = new bool{true};
        bool* checkBoxSaver = new bool{true};
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
        explicit SettingsSubView(std::shared_ptr<ViewModel::SubViewModel::SettingsSubViewModel> sVM);
        ~SettingsSubView() override;

        ftxui::Element Render() override;
    };

} // SubView
// View

#endif //STAFFDEMO_SETTINGSSUBVIEW_H
