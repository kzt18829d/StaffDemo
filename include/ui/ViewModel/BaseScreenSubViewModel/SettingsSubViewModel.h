#ifndef STAFFDEMO_SETTINGSSUBVIEWMODEL_H
#define STAFFDEMO_SETTINGSSUBVIEWMODEL_H
#include "../BasicViewModel.h"
#include "../../../core/RepositoryInstruments.h"


namespace ViewModel::SubViewModel {

    class SettingsSubViewModel : public ViewModel::BasicViewModel {
    private:
        std::weak_ptr<Core::AppSettings> appSettings;
        std::weak_ptr<Core::RepositoryInstruments> repositoryInstruments;
        int* selectedTheme = new int{0};
    public:
        explicit SettingsSubViewModel(std::shared_ptr<Core::AppSettings> sharedPtr, std::shared_ptr<Core::RepositoryInstruments> rSharedPtr);
        ~SettingsSubViewModel();

        std::vector<std::string> getThemesList() const;
        std::vector<std::string> getLocalizationList() const;

        void cleanProjectRepository();
        void cleanStaffRepository();
        void cleanAllRepository();

        void saveCurrentRepositories();

        void createNewRepositories(bool withSaveCurrent, Directory newRepositoryDirectory="");

        int* getSelectedTheme();

        boost::signals2::signal<void(bool)> cleanedStaffRepositorySignal;
        boost::signals2::signal<void(bool)> cleanedProjectRepositorySignal;
        boost::signals2::signal<void(bool)> cleanedAllRepositorySignal;
        boost::signals2::signal<void(bool)> saveCurrentRepositoriesSignal;
        boost::signals2::signal<void(bool)> createNewRepositorySignal;

    };

} // SubViewModel
// ViewModel

#endif //STAFFDEMO_SETTINGSSUBVIEWMODEL_H
