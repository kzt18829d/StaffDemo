#include "TUI.h"
#include <fmt/core.h>
namespace TUI {
    auto& dict = TranslationManager::instance().dict();
}
char TUI::START_SCREEN(const std::size_t &wWidth, const std::size_t &wHeight) {
    std::string input;
    std::string message;
    char result = 0;

    ftxui::ScreenInteractive screen = ftxui::ScreenInteractive::TerminalOutput();

    auto input_component = ftxui::Input(&input, "y/n");

    auto render2 = ftxui::Renderer(input_component, [&] {
        return ftxui::vbox({
            ftxui::hbox({
                ftxui::filler(),
                ftxui::text(TUI::dict.at("TITLE_F1")) | ftxui::center,
                ftxui::filler()
            }) | ftxui::border | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, 5),
            ftxui::vbox({
                ftxui::filler(),
                ftxui::hcenter(ftxui::text("Loading. . . .")),
                ftxui::filler(),
                ftxui::hcenter(ftxui::text(dict.at("LOADSCREEN.LQ"))),
                ftxui::hcenter(input_component->Render()),
                ftxui::hcenter(ftxui::text(message)),
                ftxui::filler()
            }) | ftxui::border | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, static_cast<int>(wHeight) - 5)
        }) | ftxui::size(ftxui::WIDTH, ftxui::EQUAL, static_cast<int>(wWidth)) | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, static_cast<int>(wHeight));
    });

    auto final_component = ftxui::CatchEvent(render2, [&](const ftxui::Event& event) {
        if (event == ftxui::Event::Return) {
            if (input == "y" || input == "Y" || input == "н" || input == "Н") {
                result = 'y';
                screen.Exit();
                return true;
            } else if (input == "n" || input == "N" || input == "т" || input == "Т") {
                result = 'n';
                screen.Exit();
                return true;
            } else {
                message = dict.at("LOADSCREEN.ERROR.INPUT");
                input.clear();
                return true;
            }
        }
        if (event.is_mouse())
            return true; // Блокируем мышь
        return false;
    });

    screen.Loop(final_component);
    return result;
}

void TUI::LOAD_SCREEN(const size_t &wWidth, const size_t &wHeight,
                      std::unordered_map<std::string, std::unique_ptr<Employee>> &STAFF,
                      std::unordered_multimap<std::string, Project *> &PROJECT_LIST) {


    int TableWidthK{20};
    int TableWidthV{30};
    std::string _id, _name, _salary, _position = "seniormanager", _project, _nightBonus, PoB, PADD, tHeading;
    std::string message;

    if (_id.empty()) _id = "N/A";
    if (_name.empty()) _name = "N/A";
    if (_position.empty()) _position = "N/A";
    if (_salary.empty()) _salary = "N/A";
    if (_nightBonus.empty()) _nightBonus = "N/A";
    if (_project.empty()) _project = "N/A";
    if (PoB.empty()) PoB = "N/A";
    if (PADD.empty()) PADD = "N/A";
    if (tHeading.empty()) tHeading = "N/A";

    auto InputSalary = ftxui::Input(&_salary, "N/A, int");
    auto InputNBonus = ftxui::Input(&_nightBonus, "N/A, int");
    auto InputPoB = ftxui::Input(&PoB, "N/A, int");
    auto InputPADD = ftxui::Input(&PADD, "N/A, int");
    auto InputTHEADING = ftxui::Input(&tHeading, "N/A, int");

    auto EmplINFO_MAIN = ftxui::Table();

    if (_position == "cleaner"){
        EmplINFO_MAIN = ftxui::Table({ // All Employees
            {fmt::format("{:^{}}", dict.at("table.KEY"), TableWidthK), fmt::format("{:^{}}", dict.at("table.VALUE"), TableWidthV)},
            {fmt::format("{:^{}}", dict.at("WORDS.ID"), TableWidthK), fmt::format("{:^{}}", _id, TableWidthV)},
            {fmt::format("{:^{}}", dict.at("WORDS.Name"), TableWidthK), fmt::format("{:^{}}", _name, TableWidthV)},
            {fmt::format("{:^{}}", dict.at("Position"), TableWidthK), fmt::format("{:^{}}", _position, TableWidthV)},
            {fmt::format("{:^{}}", dict.at("personal.Salary"), TableWidthK), fmt::format("{:^{}}", _salary, TableWidthV)}
        });
    } else if (_position == "driver") {
        EmplINFO_MAIN = ftxui::Table({ // All Employees
            {fmt::format("{:^{}}", dict.at("table.KEY"), TableWidthK), fmt::format("{:^{}}", dict.at("table.VALUE"), TableWidthV)},
            {fmt::format("{:^{}}", dict.at("WORDS.ID"), TableWidthK), fmt::format("{:^{}}", _id, TableWidthV)},
            {fmt::format("{:^{}}", dict.at("WORDS.Name"), TableWidthK), fmt::format("{:^{}}", _name, TableWidthV)},
            {fmt::format("{:^{}}", dict.at("Position"), TableWidthK), fmt::format("{:^{}}", _position, TableWidthV)},
            {fmt::format("{:^{}}", dict.at("personal.Salary"), TableWidthK), fmt::format("{:^{}}", _salary, TableWidthV)},
            {fmt::format("{:^{}}", dict.at("personal.driver.NightBonus"), TableWidthK), fmt::format("{:^{}}", _nightBonus, TableWidthV)}
        });
    } else if (_position == "programmer" || _position == "tester") {
        EmplINFO_MAIN = ftxui::Table({{
            fmt::format("{:^{}}", dict.at("table.KEY"), TableWidthK), fmt::format("{:^{}}", dict.at("table.VALUE"), TableWidthV)},
            {fmt::format("{:^{}}", dict.at("WORDS.ID"), TableWidthK), fmt::format("{:^{}}", _id, TableWidthV)},
            {fmt::format("{:^{}}", dict.at("WORDS.Name"), TableWidthK), fmt::format("{:^{}}", _name, TableWidthV)},
            {fmt::format("{:^{}}", dict.at("Position"), TableWidthK), fmt::format("{:^{}}", _position, TableWidthV)},
            {fmt::format("{:^{}}", dict.at("personal.Salary"), TableWidthK), fmt::format("{:^{}}", _salary, TableWidthV)},
            {fmt::format("{:^{}}", dict.at("engineer.Project"), TableWidthK), fmt::format("{:^{}}", _project, TableWidthV)},
            {fmt::format("{:^{}}", dict.at("engineer.PartOfBudget") + _project, TableWidthK), fmt::format("{:^{}}", PoB, TableWidthV)},
            {fmt::format("{:^{}}", dict.at("engineer.ProAdditions"), TableWidthK), fmt::format("{:^{}}", PADD, TableWidthV)}
        });
    } else if (_position == "teamleader") {
        EmplINFO_MAIN = ftxui::Table({
            {fmt::format("{:^{}}", dict.at("table.KEY"), TableWidthK), fmt::format("{:^{}}", dict.at("table.VALUE"), TableWidthV)},
            {fmt::format("{:^{}}", dict.at("WORDS.ID"), TableWidthK), fmt::format("{:^{}}", _id, TableWidthV)},
            {fmt::format("{:^{}}", dict.at("WORDS.Name"), TableWidthK), fmt::format("{:^{}}", _name, TableWidthV)},
            {fmt::format("{:^{}}", dict.at("Position"), TableWidthK), fmt::format("{:^{}}", _position, TableWidthV)},
            {fmt::format("{:^{}}", dict.at("personal.Salary"), TableWidthK), fmt::format("{:^{}}", _salary, TableWidthV)},
            {fmt::format("{:^{}}", dict.at("engineer.Project"), TableWidthK), fmt::format("{:^{}}", _project, TableWidthV)},
            {fmt::format("{:^{}}", dict.at("engineer.PartOfBudget") + _project, TableWidthK), fmt::format("{:^{}}", PoB, TableWidthV)},
            {fmt::format("{:^{}}", dict.at("engineer.ProAdditions"), TableWidthK), fmt::format("{:^{}}", PADD, TableWidthV)},
            {fmt::format("{:^{}}", dict.at("teamleader.TeamHeading"), TableWidthK), fmt::format("{:^{}}", tHeading, TableWidthV)}
        });
    } else if (_position == "projectmanager") {
        EmplINFO_MAIN = ftxui::Table({
             {fmt::format("{:^{}}", dict.at("table.KEY"), TableWidthK), fmt::format("{:^{}}", dict.at("table.VALUE"), TableWidthV)},
             {fmt::format("{:^{}}", dict.at("WORDS.ID"), TableWidthK), fmt::format("{:^{}}", _id, TableWidthV)},
             {fmt::format("{:^{}}", dict.at("WORDS.Name"), TableWidthK), fmt::format("{:^{}}", _name, TableWidthV)},
             {fmt::format("{:^{}}", dict.at("Position"), TableWidthK), fmt::format("{:^{}}", _position, TableWidthV)},
             {fmt::format("{:^{}}", dict.at("personal.Salary"), TableWidthK), fmt::format("{:^{}}", _salary, TableWidthV)},
             {fmt::format("{:^{}}", dict.at("engineer.Project"), TableWidthK), fmt::format("{:^{}}", _project, TableWidthV)},
             {fmt::format("{:^{}}", dict.at("engineer.PartOfBudget") + _project, TableWidthK), fmt::format("{:^{}}", PoB, TableWidthV)},
             {fmt::format("{:^{}}", dict.at("engineer.ProAdditions"), TableWidthK), fmt::format("{:^{}}", PADD, TableWidthV)},
             {fmt::format("{:^{}}", dict.at("teamleader.TeamHeading"), TableWidthK), fmt::format("{:^{}}", tHeading, TableWidthV)}
        });
    } else if (_position == "seniormanager") {
        EmplINFO_MAIN = ftxui::Table({
             {fmt::format("{:^{}}", dict.at("table.KEY"), TableWidthK), fmt::format("{:^{}}", dict.at("table.VALUE"), TableWidthV)},
             {fmt::format("{:^{}}", dict.at("WORDS.ID"), TableWidthK), fmt::format("{:^{}}", _id, TableWidthV)},
             {fmt::format("{:^{}}", dict.at("WORDS.Name"), TableWidthK), fmt::format("{:^{}}", _name, TableWidthV)},
             {fmt::format("{:^{}}", dict.at("Position"), TableWidthK), fmt::format("{:^{}}", _position, TableWidthV)},
             {fmt::format("{:^{}}", dict.at("personal.Salary"), TableWidthK), fmt::format("{:^{}}", _salary, TableWidthV)},
             {fmt::format("{:^{}}", dict.at("engineer.PartOfBudget") + _project, TableWidthK), fmt::format("{:^{}}", PoB, TableWidthV)},
             {fmt::format("{:^{}}", dict.at("engineer.ProAdditions"), TableWidthK), fmt::format("{:^{}}", PADD, TableWidthV)},
             {fmt::format("{:^{}}", dict.at("teamleader.TeamHeading"), TableWidthK), fmt::format("{:^{}}", tHeading, TableWidthV)},
             {fmt::format("{:^{}}", dict.at("smanager.Projects"), TableWidthK), fmt::format("{:^{}}", _project, TableWidthV)}
        });
    }

    EmplINFO_MAIN.SelectAll().Border(ftxui::LIGHT);
    EmplINFO_MAIN.SelectColumn(0).BorderRight();
    EmplINFO_MAIN.SelectColumn(0).Decorate(ftxui::bold);
    EmplINFO_MAIN.SelectColumn(0).SeparatorHorizontal();
    EmplINFO_MAIN.SelectAll().SeparatorHorizontal();
    EmplINFO_MAIN.SelectAll().SeparatorVertical();


//    auto NextButton = ftxui::Button("Save and go next", )
    auto TableRend = EmplINFO_MAIN.Render();

    auto render = ftxui::Renderer([&]{
        return ftxui::vbox({
            ftxui::hbox({
                ftxui::filler(),
                ftxui::text(TUI::dict.at("TITLE_F1")) | ftxui::center,
                ftxui::filler()
            }) | ftxui::border | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, 5),
            ftxui::vbox({
                ftxui::filler(),
                ftxui::hbox({
                    TableRend | ftxui::hcenter,
                })| ftxui::hcenter,
                ftxui::filler()
            }) | ftxui::border | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, static_cast<int>(wHeight) - 4)
        }) | ftxui::size(ftxui::WIDTH, ftxui::EQUAL, static_cast<int>(wWidth));
    });


//    auto final_component = ftxui::CatchEvent(render, [&](const ftxui::Event &event) {
//        if (event == ftxui::Event::Return) {
//            if (_salary == "y" || _salary == "Y") {
//                screen.Exit();
//                return true;
//            } else if (_salary == "n" || _salary == "N") {
//                screen.Exit();
//                return true;
//            } else {
//                message = dict.at("LOADSCREEN.ERROR.INPUT");
//                return true;
//            }
//        }
//        if (event.is_mouse())
//            return true; // Блокируем мышь
//        return false;
//    });
    ftxui::ScreenInteractive screen = ftxui::ScreenInteractive::TerminalOutput();
    screen.Loop(render);
}


