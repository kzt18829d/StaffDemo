#include <ftxui/component/event.hpp>
#include "../../include/ui/ScreenManager.h"

ScreenManager::ScreenManager() {
    stackedContainer = ftxui::Container::Stacked({});
    Add(stackedContainer);
}

bool ScreenManager::addScreen(const std::string &screenName, ftxui::Component screen_) {
    if (screensID.contains(screenName)) {
        //< log
        return false;
    }
    screensInfo.push_back({screenName, screen_});
    screensID[screenName] = screensID.size() - 1;
    stackedContainer->Add(screen_);
    return true;
}

bool ScreenManager::showScreen(const std::string &screenName) {
    if (auto iterator = screensID.find(screenName); iterator != screensID.end()) {
        auto index = iterator->second;
        if (index > screensInfo.size()) return false;
        stackedContainer->SetActiveChild(screensInfo.at(index).component.get());
        activeScreen = (int)index;
        return true;
    }
    return false;
}

ftxui::Element ScreenManager::Render() {
//     return stackedContainer->Render(); // раскомментить, но закомментить нижние строки
    if (!(activeScreen != -1 && activeScreen < screensInfo.size())) {
        //< log
        return ftxui::text("No screen on this activeScreen position");
    }
    return screensInfo[activeScreen].component->Render();
}

bool ScreenManager::OnEvent(ftxui::Event event) {
    return stackedContainer->OnEvent(event);
}

std::string ScreenManager::getActiveScreenName() const {
    if (!(activeScreen == -1 or activeScreen >= screensID.size())) {
        for (const auto &pair: screensID) if (pair.second == activeScreen) return pair.first;
    }
    return "No screen";
}

ftxui::Component ScreenManager::getActiveScreenComponent() {
    if (activeScreen != -1 && activeScreen < screensID.size()) return screensInfo.at(activeScreen).component;
    return nullptr;
}
