//
// Created by hid3h on 17.06.2025.
//

#include "SettingsSubView.h"


namespace View::SubView {
    SettingsSubView::SettingsSubView(std::shared_ptr<ViewModel::SubViewModel::SettingsSubViewModel> sVM) : BasicView(sVM), subViewModel(sVM) {
        ThemeTextWindow = subViewModel->getTranslate("VIEW_SettingsSubView_ThemeTextWindow");
        themeText = subViewModel->getTranslate("VIEW_SettingsSubView_themeText");
        currentThemeText = subViewModel->getTheme().name;
        changeThemeText = subViewModel->getTranslate("VIEW_SettingsSubView_changeThemeText");
        ThemesDropdown = Dropdown(subViewModel->getThemesList(), subViewModel->getSelectedTheme());
        CreateThemeButton = Button(subViewModel->getTranslate("VIEW_SettingsSubView_CreateThemeButton"), []{
            // logic
        });
        Hoverable(CreateThemeButton, canHoverableThemeButton);

        LanguageTextWindow = subViewModel->getTranslate("VIEW_SettingsSubView_LanguageTextWindow");
        languageText = subViewModel->getTranslate("VIEW_SettingsSubView_LanguageText");
        currentLanguageText = "English/red";

        RepositoryTextWindow = subViewModel->getTranslate("VIEW_SettingsSubView_RepositoryTextWindow");
        repositoryWarning = subViewModel->getTranslate("VIEW_SettingsSubView_RepositoryWarning");
        saveRepositoryButton = Button(subViewModel->getTranslate("VIEW_SettingsSubView_saveRepositoryButton"), [&]{
            subViewModel->saveCurrentRepositories();
        });
        createRepositoryCheckboxText = subViewModel->getTranslate("VIEW_SettingsSubView_createRepositoryCheckboxText");
        createRepositoryCheckBox = Checkbox(createRepositoryCheckboxText, checkBoxSaver);
        createNewRepositoryButton = Button(subViewModel->getTranslate("VIEW_SettingsSubView_createNewRepositoryButton"), [&]{
            subViewModel->createNewRepositories(*checkBoxSaver);
        });

        windowContainer = ftxui::Container::Vertical({
            ThemesDropdown, CreateThemeButton
        });
    }

    SettingsSubView::~SettingsSubView() {
        delete checkBoxSaver;
        delete canHoverableThemeButton;
    }

    ftxui::Element SettingsSubView::Render() {
        auto themeSettings = vbox({
            hbox({
                filler() | size(WIDTH, EQUAL, bord),
                text(themeText),
                filler() | size(WIDTH, EQUAL, interblockBord),
                text(currentThemeText)
            }),
            hbox({
                filler()| size(WIDTH, EQUAL, bord),
                text(changeThemeText),
                filler() | size(WIDTH, EQUAL, interblockBord),
                ThemesDropdown->Render()
            })
        });
        auto themeSettingsWindow = window(text(ThemeTextWindow), themeSettings);

        auto LanguageSettings = vbox({
            hbox({
                filler() | size(WIDTH, EQUAL, bord),
                text(languageText),
                filler() | size(WIDTH, EQUAL, interblockBord),
                text((currentLanguageText))
            }),
            hbox({
                filler() | size(WIDTH, EQUAL, bord),
                text(changeLanguageText),
                filler() | size(WIDTH, EQUAL, interblockBord),
                LanguagesDropdown->Render()
            })
        });
        auto LanguageSettingsWindow = window(text(LanguageTextWindow), LanguageSettings);

        auto RepositorySettings = vbox({
            hbox({
                //adddddd
            })
        });
        auto RepositorySettingsWindow = window(text(RepositoryTextWindow), RepositorySettings);

        return vbox({
            themeSettingsWindow,
            LanguageSettingsWindow,
            RepositorySettingsWindow
        });
    }
} // SubView
// View