//
// Created by hid3h on 08.06.2025.
//

#ifndef STAFFDEMO_STARTSCREENVIEWMODEL_H
#define STAFFDEMO_STARTSCREENVIEWMODEL_H
#include "BasicViewModel.h"
#include "memory"
#include "string"
#include "core/AppSetting.h"
#include "core/Usages.h"
namespace ViewModel {

    ///@brief Модель представления стартового окна
    ///@ingroup ViewModel
    ///@see BasicViewModel
    class StartScreenViewModel : public BasicViewModel {
    private:
        Message statusMessage;
        Message checkBoxMessage;
        Directory staffDirectory;

        bool* autoLoadEmployeesCheckBox_bool = new bool(false);

    public:
        explicit StartScreenViewModel(std::shared_ptr<Core::AppSettings> _appSettings);
        ~StartScreenViewModel();

        Message getStatusMessage() const;
        Message getCheckBoxMessage() const;
        Directory getStaffDirectory() const;
        Directory getStaffDirectoryFromSettings() const;

        void updateStatusMessage(Message& updatedMessage);
        Message& setStaffDirectory();

        bool* getAutoLoadEmployeesCheckBox_bool();

        void useDefaultSettings();
        void useCustomSettings();

        boost::signals2::signal<void(WindowType nextScreen)> applySettingsSignal;
        boost::signals2::signal<void(Message&)> statusMessageChangedSignal;

    };

} // ViewModel

#endif //STAFFDEMO_STARTSCREENVIEWMODEL_H
