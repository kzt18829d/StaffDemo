//
// Created by hid3h on 08.06.2025.
//

#include "ui/ViewModel/StartScreenViewModel.h"
#include "core/ScreensENUM.h"

namespace ViewModel {
    StartScreenViewModel::StartScreenViewModel(std::shared_ptr<Core::AppSettings> sharedPtr) : BasicViewModel(sharedPtr) {
        if (appSettings.lock()) this->staffDirectory = appSettings.lock()->getStaffDirectory();
        //translate
        this->checkBoxMessage = "Use auto loading from file?";
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
        if (*autoLoadEmployeesCheckBox_bool == true) applySettingsSignal(WindowType::LOAD_EMPLOYEES_WINDOW_auto);
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

    bool* StartScreenViewModel::getAutoLoadEmployeesCheckBox_bool() {
        return autoLoadEmployeesCheckBox_bool;
    }

    Directory StartScreenViewModel::getStaffDirectoryFromSettings() const {
        return appSettings.lock()->getStaffDirectory();
    }

    StartScreenViewModel::~StartScreenViewModel() {
        delete autoLoadEmployeesCheckBox_bool;
    }

} // ViewModel