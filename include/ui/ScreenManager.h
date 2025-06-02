//
// Created by hid3h on 29.05.2025.
//

#ifndef STAFFDEMO_SCREENMANAGER_H
#define STAFFDEMO_SCREENMANAGER_H
#include "vector"
#include "memory"
#include "map"
#include "string"
#include "ftxui/component/component.hpp"

class ScreenManager : ftxui::ComponentBase {
private:
    struct ScreenType {
        std::string screenName;
        ftxui::Component component;
    };
    std::vector<ScreenType> screensInfo;
    std::map<std::string, std::size_t> screensID;
    ftxui::Component stackedContainer;
    int activeScreen = -1;
public:
    ScreenManager();
    bool addScreen(const std::string& screenName, ftxui::Component screen_);
    bool showScreen(const std::string& screenName);
    ftxui::Element Render() override;
    bool OnEvent(ftxui::Event event) override;

    std::string getActiveScreenName() const;
    ftxui::Component getActiveScreenComponent();
};


#endif //STAFFDEMO_SCREENMANAGER_H
