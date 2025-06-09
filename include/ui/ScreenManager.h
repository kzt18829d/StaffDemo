//
// Created by hid3h on 29.05.2025.
//

#ifndef STAFFDEMO_SCREENMANAGER_H
#define STAFFDEMO_SCREENMANAGER_H
#include "ftxui/component/component_base.hpp"
#include "ftxui/component/component.hpp"
#include <ftxui/component/event.hpp>
#include "View/BasicView.h"
#include "../core/ScreensENUM.h"
#include "../core/Usages.h"
#include "vector"
#include "string"
#include "map"

///@namespace UI
namespace UI {

    ///@brief Менеджер экранов
    ///@details Руководит экранами, добавляя новые, и переключаясь между ними.
    ///@ingroup TextUserInterface
    class ScreenManager : public ftxui::ComponentBase {
    public:
        using ScreenName = std::string;
    private:
        ftxui::Component screenContainer;
        std::map<WindowType, ftxui::Component> screenMap;
        WindowType ACTIVE_SCREEN = WindowType::NULL_SCREEN;

    public:
        ScreenManager();
        ~ScreenManager() override;
        void addScreen(WindowType enumScreenName, std::shared_ptr<View::BasicView> screen);
        void showScreen(WindowType enumScreenName);

        ftxui::Element Render() override;
        bool OnEvent(ftxui::Event event) override;

        ScreenName getActiveScreenString();
        ftxui::Component getActiveScreenComponent();
        WindowType getActiveScreenEnum();

        ScreenManager(ScreenManager &) = delete;
        ScreenManager(ScreenManager &&) = delete;
        ScreenManager &operator=(ScreenManager &) = delete;
        ScreenManager &operator=(ScreenManager &&) = delete;
    };
}

#endif //STAFFDEMO_SCREENMANAGER_H
