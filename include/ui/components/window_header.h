#ifndef STAFFDEMO_WINDOW_HEADER_H
#define STAFFDEMO_WINDOW_HEADER_H
#include <memory>
#include <ftxui/component/component.hpp>
#include "utils/TranslationManager.h"


namespace StaffDemo::UI {
    class WINDOWS_HEADER {
    private:
        std::shared_ptr<ftxui::ComponentBase> header = ftxui::Renderer([] {
            return ftxui::hbox({
                ftxui::filler(),
                ftxui::text(StaffDemo::Utils::TranslationManager::instance().dict().at("TITLE_F1")) | ftxui::center,
                ftxui::filler()
            }) | ftxui::border | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, 5);
        });
    public:
        std::shared_ptr<ftxui::ComponentBase> get() {
            return header;
        }
    };
} // UI
// StaffDemo

#endif //STAFFDEMO_WINDOW_HEADER_H
