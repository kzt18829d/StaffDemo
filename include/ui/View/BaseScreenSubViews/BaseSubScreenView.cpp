#include "BaseSubScreenView.h"


namespace View::SubView {
    BaseSubScreenView::BaseSubScreenView(std::shared_ptr<ViewModel::SubViewModel::BaseSubScreenViewModel> sharedPtr) : BasicView(sharedPtr), subViewModel(sharedPtr) {
        initTranslates();
    }

    BaseSubScreenView::~BaseSubScreenView() {

    }

    ftxui::Element BaseSubScreenView::Render() {
        const auto& theme = subViewModel->getTheme();

        auto projectBox = vbox({
           hbox({ text(TitleText) }) | hcenter | color(theme.text_window_header),
           hbox({ text(subTitleText) }) | hcenter | color(theme.text_window_header),
           filler() | size(HEIGHT, EQUAL, 1),
           hbox({ paragraphAlignCenter(detailsTitle) | size(WIDTH, EQUAL, 80) }) | hcenter | color(theme.text_primary)
        });

        auto authorBox = vbox({
            hbox({
                filler() | size(WIDTH, EQUAL, 10),
                text(AuthorText) | size(WIDTH, EQUAL, 15),
                text(Author)
            }) | color(theme.text_success),
            filler() | size(HEIGHT, EQUAL, 1),
             hbox({
                filler() | size(WIDTH, EQUAL, 10),
                hyperlink(authorHyperLink, text(authorHyperLink)) | color(theme.text_primary),
                filler() | size(WIDTH, EQUAL, 5),
                hyperlink(projectHyperLink, text(projectHyperLink)) | color(theme.text_primary)
            })
        });

        return vbox({
            filler() | size(HEIGHT, EQUAL, 3),
            filler() | size(WIDTH, EQUAL, 15), projectBox | flex,
            filler() | size(HEIGHT, EQUAL, 2),
            filler() | size(WIDTH, EQUAL, 15), authorBox | flex
        }) | bgcolor(theme.bg_primary);
    }

    void BaseSubScreenView::initTranslates() {
        TitleText = subViewModel->getTranslate("TITLE1");
        subTitleText = subViewModel->getTranslate("TITLE2");
        detailsTitle = subViewModel->getTranslate("VIEW_BaseSubView_detailsTitle");
        Author = "kzt18829d";
        AuthorText = subViewModel->getTranslate("VIEW_BaseSubView_AuthorText");
        authorHyperLink = "https://github.com/kzt18829d";
        projectHyperLink = "https://github.com/kzt18829d/StaffDemo";
    }
} // SubView
// View