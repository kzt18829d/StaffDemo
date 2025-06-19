//
// Created by hid3h on 19.06.2025.
//

#ifndef STAFFDEMO_BASESUBSCREENVIEW_H
#define STAFFDEMO_BASESUBSCREENVIEW_H
#include "../BasicView.h"
#include "../../ViewModel/BaseScreenSubViewModel/BaseSubScreenViewModel.h"


namespace View::SubView {

    class BaseSubScreenView : public BasicView {
    private:
        std::shared_ptr<ViewModel::SubViewModel::BaseSubScreenViewModel> subViewModel;
        Text TitleText, subTitleText;
        Text detailsTitle;
        Text Author, AuthorText;
        Text year;
        Text authorHyperLink, projectHyperLink;

    public:
        explicit BaseSubScreenView(std::shared_ptr<ViewModel::SubViewModel::BaseSubScreenViewModel> sharedPtr);
        ~BaseSubScreenView() override;
        ftxui::Element Render() override;
        void initTranslates();
    };

} // SubView
// View

#endif //STAFFDEMO_BASESUBSCREENVIEW_H
