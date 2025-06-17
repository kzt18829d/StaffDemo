//
// Created by hid3h on 17.06.2025.
//

#include "ui/View/BaseScreenSubViews/SettingsSubView.h"


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
        changeLanguageText = subViewModel->getTranslate("VIEW_SettingsSubView_changeLanguageText");
        LanguagesDropdown = Dropdown(subViewModel->getLocalizationList(), subViewModel->getSelectedLang());

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
            ThemesDropdown,
//            CreateThemeButton,
            LanguagesDropdown,
            saveRepositoryButton,
            createNewRepositoryButton
        });

        Add(windowContainer);
    }

    SettingsSubView::~SettingsSubView() {
        delete checkBoxSaver;
        delete canHoverableThemeButton;
    }

    ftxui::Element SettingsSubView::Render() {
        const auto & theme = subViewModel->getTheme();
        auto themeSettings = vbox({
            filler() | size(HEIGHT, EQUAL, 1),
            hbox({
                filler() | size(WIDTH, EQUAL, bord),
                text(fmt::format("{:<{}}", themeText, 20)) | color(theme.text_primary),
                filler() | size(WIDTH, EQUAL, interblockBord),
                text(fmt::format("{:<{}}", currentThemeText, 20)) | color(theme.text_primary)
            }),
            hbox({
                filler()| size(WIDTH, EQUAL, bord),
                vbox({
                    filler()| size(HEIGHT, EQUAL, 1),
                    text(fmt::format("{:<{}}", changeThemeText, 20)) | color(theme.text_primary)
                }),
                filler() | size(WIDTH, EQUAL, interblockBord - 2),
                ThemesDropdown->Render() | size(WIDTH, EQUAL, 20) | color(theme.text_primary)
            }),
            filler() | size(HEIGHT, EQUAL, 1),
        });
        auto themeSettingsWindow = window(text(ThemeTextWindow), themeSettings);

        auto LanguageSettings = vbox({
            filler() | size(HEIGHT, EQUAL, 1),
            hbox({
                filler() | size(WIDTH, EQUAL, bord),
                text(fmt::format("{:<{}}", languageText, 20)) | color(theme.text_primary),
                filler() | size(WIDTH, EQUAL, interblockBord),
                text(fmt::format("{:<{}}", currentLanguageText, 30)) | color(theme.text_primary)
            }),
            hbox({
                filler() | size(WIDTH, EQUAL, bord),
                vbox({
                    filler() | size(HEIGHT, EQUAL, 1),
                    text(fmt::format("{:<{}}", changeLanguageText, 20)) | color(theme.text_primary)
                }),
                filler() | size(WIDTH, EQUAL, interblockBord - 2),
                LanguagesDropdown->Render() | size(WIDTH, EQUAL, 20) | color(theme.text_primary)
            }),
            filler() | size(HEIGHT, EQUAL, 1),
        });
        auto LanguageSettingsWindow = window(text(LanguageTextWindow), LanguageSettings);

        auto RepositorySettings = vbox({
//            filler() | size(HEIGHT, EQUAL, 1),
            hbox({
                filler() | size(WIDTH, EQUAL, bord),
                text(repositoryWarning) | color(theme.text_warning),
            }),
            hbox({
                filler() | size(WIDTH, EQUAL, bord),
                saveRepositoryButton->Render(),
                filler() | size(WIDTH, EQUAL, 10),
                createNewRepositoryButton->Render()
            }),
//            filler() | size(HEIGHT, EQUAL, 1),
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