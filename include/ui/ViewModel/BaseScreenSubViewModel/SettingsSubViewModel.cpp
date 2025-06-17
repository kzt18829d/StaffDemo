//
// Created by hid3h on 17.06.2025.
//

#include "SettingsSubViewModel.h"


namespace ViewModel::SubViewModel {
    SettingsSubViewModel::SettingsSubViewModel(std::shared_ptr<Core::AppSettings> sharedPtr, std::shared_ptr<Core::RepositoryInstruments> rSharedPtr) : BasicViewModel(
            sharedPtr), appSettings(sharedPtr), repositoryInstruments(rSharedPtr) {

    }

    SettingsSubViewModel::~SettingsSubViewModel() {
        delete selectedTheme;
    }

    std::vector<std::string> SettingsSubViewModel::getThemesList() const {
        return appSettings.lock()->themeManager->getThemeNamesList();
    }

    std::vector<std::string> SettingsSubViewModel::getLocalizationList() const {
//        return appSettings.lock()->translationStorageProvider->
        return std::vector<std::string> {
            appSettings.lock()->translationManager->tr("LOCALIZATION_RU"),
            appSettings.lock()->translationManager->tr("LOCALIZATION_EN"),
            appSettings.lock()->translationManager->tr("LOCALIZATION_JP"),
            appSettings.lock()->translationManager->tr("LOCALIZATION_CH")
        };
    }

    void SettingsSubViewModel::cleanProjectRepository() {
        bool cleanProject = repositoryInstruments.lock()->projectRepository->clean();
        cleanedProjectRepositorySignal(cleanProject);
    }

    void SettingsSubViewModel::cleanStaffRepository() {
        bool cleanStaff = repositoryInstruments.lock()->staffRepository->clean();
        cleanedStaffRepositorySignal(cleanStaff);
    }

    void SettingsSubViewModel::cleanAllRepository() {
        bool cleanStaff = repositoryInstruments.lock()->staffRepository->clean();
        bool cleanProject = repositoryInstruments.lock()->projectRepository->clean();
        if (cleanStaff && cleanProject) cleanedAllRepositorySignal(true);
        else cleanedAllRepositorySignal(false);
    }

    void SettingsSubViewModel::saveCurrentRepositories() {
        bool saveCurrent = repositoryInstruments.lock()->savePersonalData();
        saveCurrentRepositoriesSignal(saveCurrent);
    }

    void SettingsSubViewModel::createNewRepositories(bool withSaveCurrent, Directory newRepositoryDirectory) {
        if (newRepositoryDirectory.empty() || newRepositoryDirectory == appSettings.lock()->getStaffDirectory()) {
            if (withSaveCurrent){
                bool check1 = repositoryInstruments.lock()->createNewPersonalDataWithSave();
                saveCurrentRepositoriesSignal(check1);
                createNewRepositorySignal(check1);
            } else {
                bool check2 = repositoryInstruments.lock()->createNewPersonalDataWithoutSave();
                createNewRepositorySignal(check2);
            }
        } else {
            if (withSaveCurrent) {
                bool check3_1 = repositoryInstruments.lock()->createNewPersonalDataWithSave(newRepositoryDirectory);
                if (check3_1) appSettings.lock()->setStaffDirectory(newRepositoryDirectory);
                createNewRepositorySignal(check3_1);
            } else {
                bool check4 = repositoryInstruments.lock()->createNewPersonalDataWithoutSave(newRepositoryDirectory);
                if (check4) appSettings.lock()->setStaffDirectory(newRepositoryDirectory);
                createNewRepositorySignal(check4);
            }
        }
    }

    int *SettingsSubViewModel::getSelectedTheme() {
        return selectedTheme;
    }
} // SubViewModel
// ViewModel