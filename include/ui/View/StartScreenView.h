//
// Created by hid3h on 08.06.2025.
//

#ifndef STAFFDEMO_STARTSCREENVIEW_H
#define STAFFDEMO_STARTSCREENVIEW_H
#include "BasicView.h"
#include "../ViewModel/StartScreenViewModel.h"
#include "core/Usages.h"

namespace View {

    ///@brief Представление стартового экрана
    ///@ingroup View
    class StartScreenView : public BasicView {
    private:
        std::shared_ptr<ViewModel::StartScreenViewModel> viewModel;
        Message statusMessage;
        Message checkBoxMessage;

        InputOption StaffDirectoryInputOption;
        CheckboxOption autoLoadCheckBoxOption;

        ftxui::Component staffDirectoryInput;
        ftxui::Component autoLoadCheckBox;
        ftxui::Component defaultSettingsButton;
        ftxui::Component customSettingsButton;

        ftxui::Component windowContainer;

        void updateStatusMessage(Message& newMessage);

        boost::signals2::connection statusMessageChangedConnection;

    public:
        explicit StartScreenView(const std::shared_ptr<ViewModel::StartScreenViewModel>& _viewModel);
        ftxui::Element Render() override;
    };

} // View

#endif //STAFFDEMO_STARTSCREENVIEW_H
