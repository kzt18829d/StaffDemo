#ifndef STAFFDEMO_VIEWBASE_H
#define STAFFDEMO_VIEWBASE_H
#include <utility>

#include "ftxui/component/component.hpp"
#include "ftxui/component/component_base.hpp"
#include "ftxui/component/screen_interactive.hpp"
#include "ftxui/component/event.hpp"
#include "../../core/ThemeManager.h"
#include "../../core/Signal2.h"
#include "memory"
#include "../ViewModel/ViewModelBase.h"

namespace StaffDemo::UI {

class ViewBase : public ftxui::ComponentBase, public ftxui::Component {
    private:
        Core::Connection<const Theme&> themeChangedConnection;
    protected:
        std::shared_ptr<ViewModelBase> viewModel;
        Theme& getTheme() const { return Core::ThemeManager::instance().getTheme(); }
        virtual void themeChanged(Theme& newTheme) {
            (void)newTheme; // сделать принудительное обновление через сигналы
        }

    public:
        ViewBase(std::shared_ptr<ViewModelBase> viewModelBase) : viewModel(std::move(viewModelBase)) {
            themeChangedConnection = Core::ThemeManager::instance().ThemeChangedSignal.connect([this](Theme newTheme){ themeChanged(newTheme); });
        }

        ~ViewBase() override { if (themeChangedConnection.connected()) themeChangedConnection.disconnect(); }

        virtual ftxui::Element Render() override = 0;

//        ViewBase(const ViewBase&) = delete;
        ViewBase(ViewBase&&) = delete;
        ViewBase& operator=(const ViewBase&) = delete;
        ViewBase& operator=(ViewBase&&) = delete;
    };

} // UI
// StaffDemo

#endif //STAFFDEMO_VIEWBASE_H
