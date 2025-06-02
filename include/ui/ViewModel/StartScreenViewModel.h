//
// Created by hid3h on 29.05.2025.
//

#ifndef STAFFDEMO_STARTSCREENVIEWMODEL_H
#define STAFFDEMO_STARTSCREENVIEWMODEL_H
#include "ViewModelBase.h"
#include "../AppSetting.h"
#include "../../core/Signal2.h"
#include "memory"
#include "../../utils/Functions.h"

namespace Model {
    class StartScreenViewModel : public StaffDemo::UI::ViewModelBase {
    private:
        std::string statusMessage;
        std::string themeDirectory;
        std::string staffDirectory;
        std::shared_ptr<AppSettings> appSettings;
    public:
        StartScreenViewModel(std::shared_ptr<AppSettings> settings);

        std::string getStaffDir() const;
        std::string getThemeDir() const;
        std::string getStatusMessage() const;
        void updateStatusMessage(const std::string& newMessage);

        std::string& setStaffDir();

        void ApplySettings();
        void DefaultSettings();

        StaffDemo::Core::Signal<> applySettingSignal;
        StaffDemo::Core::Signal<const std::string&> statusMessageChangedSignal;
    };

} // Model

#endif //STAFFDEMO_STARTSCREENVIEWMODEL_H
