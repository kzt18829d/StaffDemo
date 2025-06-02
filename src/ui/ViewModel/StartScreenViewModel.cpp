//
// Created by hid3h on 29.05.2025.
//

#include "../../../include/ui/ViewModel/StartScreenViewModel.h"

namespace Model {
    void StartScreenViewModel::updateStatusMessage(const std::string &newMessage) {
        statusMessage = std::move(newMessage);
        statusMessageChangedSignal(statusMessage);
    }

    StartScreenViewModel::StartScreenViewModel(std::shared_ptr<AppSettings> settings) : appSettings(settings) {
        if (appSettings) {
            staffDirectory = appSettings->staffDataDirectory;
            //сюда потом добавить тему
        }
//        LOG_INFO << "StartScreenViewModel created.";
    }

    std::string StartScreenViewModel::getStaffDir() const {
        return staffDirectory;
    }

    std::string StartScreenViewModel::getThemeDir() const {
        return themeDirectory;
    }

    std::string StartScreenViewModel::getStatusMessage() const {
        return statusMessage;
    }

    void StartScreenViewModel::ApplySettings() {
        if (!appSettings) {
            updateStatusMessage("AppSettings error.");
            return;
        }
        if (staffDirectory.empty()) {
           DefaultSettings();
            return;
        }
        else {
            if (File::openFile(staffDirectory)) {
                appSettings->staffDataDirectory = staffDirectory;
            }
            else updateStatusMessage("Incorrect staffDirectory");
        }

        updateStatusMessage("Load.");
        applySettingSignal();
    }

    void StartScreenViewModel::DefaultSettings() {
        staffDirectory = appSettings->staffDataDirectory;
        themeDirectory = appSettings->themeDataDirectory;
    }

    std::string& StartScreenViewModel::setStaffDir() {
        return staffDirectory;
    }
} // Model