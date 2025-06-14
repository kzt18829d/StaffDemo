#include "BasicView.h"

namespace View {
    BasicView::BasicView(std::shared_ptr<ViewModel::BasicViewModel> viewModel) : ViewModel(std::move(viewModel)) {
    }

    BasicView::~BasicView() {
        if (themeChangedConnection.connected())     themeChangedConnection.disconnect();
        if (reRenderRequest.connected())            reRenderRequest.disconnect();
    }

    void BasicView::reRender() {
        Render();
    }



} // View