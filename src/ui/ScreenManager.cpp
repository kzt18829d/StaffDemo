#include "../../include/ui/ScreenManager.h"

namespace UI {

    ScreenManager::ScreenManager() {
        screenContainer = ftxui::Container::Stacked({});
        this->Add(screenContainer);
    }

    ScreenManager::~ScreenManager() = default;

    void ScreenManager::addScreen(WindowType enumScreenName, std::shared_ptr<View::BasicView> screen) {
        if (screenMap.contains(enumScreenName)) return;
        screenMap[enumScreenName] = screen;
        screenContainer->Add(screen);
    }

    void ScreenManager::showScreen(WindowType enumScreenName) {
        if (!screenMap.contains(enumScreenName) || ACTIVE_SCREEN == enumScreenName) {
            // log
            return; // заглушка
        }
        ACTIVE_SCREEN = enumScreenName;
        screenContainer->SetActiveChild(screenMap[enumScreenName]);
    }

    ftxui::Element ScreenManager::Render() {
        return screenContainer->Render();
    }

    bool ScreenManager::OnEvent(ftxui::Event event) {
        return screenContainer->OnEvent(event);
    }

    ScreenManager::ScreenName ScreenManager::getActiveScreenString() {
        if (ACTIVE_SCREEN == WindowType::NULL_SCREEN) return "No Active Screen";
//    return screenMap.at(ACTIVE_SCREEN);
        return ""; // заглушка
    }

    ftxui::Component ScreenManager::getActiveScreenComponent() {
        if (ACTIVE_SCREEN == WindowType::NULL_SCREEN) return nullptr;
        return screenContainer->ActiveChild();
    }

    WindowType ScreenManager::getActiveScreenEnum() {
        return ACTIVE_SCREEN;
    }

}