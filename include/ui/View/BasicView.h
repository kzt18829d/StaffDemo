//
// Created by hid3h on 08.06.2025.
//

#ifndef STAFFDEMO_BASICVIEW_H
#define STAFFDEMO_BASICVIEW_H
#include "ftxui/component/component_base.hpp"
#include "ftxui/component/component.hpp"
#include "boost/signals2.hpp"
#include "memory"
#include "core/ThemeManager.h"
#include "../ViewModel//BasicViewModel.h"

///@defgroup View

///@namespace View
namespace View {

    ///@brief Базовый класс Представлений
    ///@ingroup View
    class BasicView : public ftxui::ComponentBase {
    protected:
        std::shared_ptr<ViewModel::BasicViewModel> ViewModel;
        // Theme


        // ThemeSignalConnection
        boost::signals2::connection themeChangedConnection;
        boost::signals2::connection reRenderRequest;

        void reRender();

    public:
        explicit BasicView(std::shared_ptr<ViewModel::BasicViewModel> viewModel);
        ~BasicView() override;
        ftxui::Element Render() override;

    };

} // View

#endif //STAFFDEMO_BASICVIEW_H
