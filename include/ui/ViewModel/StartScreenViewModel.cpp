//
// Created by hid3h on 08.06.2025.
//

#include "StartScreenViewModel.h"

namespace ViewModel {
    StartScreenViewModel::StartScreenViewModel(std::shared_ptr<Core::AppSettings> sharedPtr) : BasicViewModel(sharedPtr) {
        if (appSettings.lock()) this->staffDirectory = appSettings.lock()->getStaffDirectory();
        //translate
        this->checkBoxMessage = "Use auto loading from file?";
        this->autoLoadEmployeesCheckBox_bool = std::make_shared<bool>(false);
    }

    Message StartScreenViewModel::getStatusMessage() const {
        return this->statusMessage;
    }

    Message StartScreenViewModel::getCheckBoxMessage() const {
        return this->checkBoxMessage;
    }

    Directory StartScreenViewModel::getStaffDirectory() const {
        return this->staffDirectory;
    }

    void StartScreenViewModel::updateStatusMessage(Message &updatedMessage) {
        this->statusMessage = std::move(updatedMessage);
        statusMessageChangedSignal(this->statusMessage);
    }

    Message &StartScreenViewModel::setStaffDirectory() {
        return this->staffDirectory;
    }

    void StartScreenViewModel::useDefaultSettings() {
        if (this->autoLoadEmployeesCheckBox_bool) applySettingsSignal(WindowType::LOAD_EMPLOYEES_WINDOW_auto);
        else applySettingsSignal(WindowType::LOAD_EMPLOYEES_WINDOW_hand);
    }


    void StartScreenViewModel::useCustomSettings() {
        if (this->staffDirectory.empty() || this->staffDirectory == appSettings.lock()->getStaffDirectory()) {
            useDefaultSettings();
            return;
        };
        try{
//        if (this->staffDirectory)
        } catch(...) {}
    }

    bool *StartScreenViewModel::getAutoLoadEmployeesCheckBox_bool() {
        return this->autoLoadEmployeesCheckBox_bool.get();
    }

    Directory StartScreenViewModel::getStaffDirectoryFromSettings() const {
        return appSettings.lock()->getStaffDirectory();
    }

} // ViewModel