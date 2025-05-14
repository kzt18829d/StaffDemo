#include "TUI.h"
#include <fmt/core.h>
namespace TUI {
    auto& dict = TranslationManager::instance().dict();
    using TableRow = std::pair<std::string, std::string>;
    using TableData = std::vector<TableRow>;
}

#define DICT_GET(key) TUI::dict.contains(key) ? TUI::dict.at(key) : std::string(key)
std::shared_ptr<ftxui::ComponentBase> WINDOW_HEADER = ftxui::Renderer([]{
    return ftxui::hbox({
        ftxui::filler(),
        ftxui::text(DICT_GET("TITLE_F1")) | ftxui::center,
        ftxui::filler()
    }) | ftxui::border | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, 5);
});

//template <typename ... Args>
TUI::TableData TUI::LOCAL::CreateTable(const TempEmloyee& tempE) {
    TableData table;

    table.emplace_back(DICT_GET("WORDS.ID"), tempE.id);
    table.emplace_back(DICT_GET("WORDS.Name"), tempE.name);
    table.emplace_back(DICT_GET("personal.POSITION"), tempE.position);
    table.emplace_back(DICT_GET("personal.Salary"), tempE.salary);

    if (tempE.position == "driver") {
        table.emplace_back(DICT_GET("personal.driver.NightBonus"), tempE.nBonus);
    }
    else if (tempE.position == "programmer" || tempE.position == "tester" || tempE.position == "timlid" || tempE.position == "projectm" || tempE.position == "seniorm") {
        if (tempE.position == "seniorm") {
            table.emplace_back(DICT_GET("smanager.Projects"), tempE.project);
        } else table.emplace_back(DICT_GET("engineer.Project"), tempE.project);
        table.emplace_back(DICT_GET("engineer.PartOfBudget"), tempE.PoB);
        table.emplace_back(DICT_GET("engineer.ProAdditions"), tempE.PADD);
        if (tempE.position == "timlid" || tempE.position == "seniorm") {
            table.emplace_back(DICT_GET("teamleader.TeamHeading"), tempE.tHeading);
        }
    }
    return table;
}

void TUI::LOCAL::N_A_DEF(TempEmloyee &temp) {
    if (temp.id.empty()) temp.id = "N/A";
    if (temp.name.empty()) temp.name = "N/A";
    if (temp.position.empty()) temp.position = "N/A";
    if (temp.salary.empty()) temp.salary = "N/A";
    if (temp.nBonus.empty()) temp.nBonus = "N/A";
    if (temp.project.empty()) temp.project = "N/A";
    if (temp.PoB.empty()) temp.PoB = "N/A";
    if (temp.PADD.empty()) temp.PADD = "N/A";
    if (temp.tHeading.empty()) temp.tHeading = "N/A";
}

void TUI::LOCAL::N_A_DEL(TempEmloyee &temp) {
    if (temp.id == "N/A" || temp.id.empty()) throw staff::except::IncorrectField("nID");
    if (temp.name == "N/A" || temp.name.empty()) throw staff::except::IncorrectField("nName");
    if (temp.position.empty() || temp.position == "N/A") throw staff::except::IncorrectField("nPOSITION");
    if (temp.salary.empty() || temp.salary == "N/A") temp.salary = "0";
    if (temp.nBonus.empty() || temp.nBonus == "N/A") temp.nBonus = "0";
    if (temp.project.empty() || temp.project == "N/A") temp.project = "";
    if (temp.PoB.empty() || temp.PoB == "N/A") temp.PoB = "0";
    if (temp.PADD.empty() || temp.PADD == "N/A") temp.PADD = "0";
    if (temp.tHeading.empty() || temp.PADD == "N/A") temp.tHeading = "0";
}


void TUI::END_SCREEN(const size_t &wWidth, const size_t &wHeight, const std::string &WindowMessage) {
#if defined(_WIN32)
    system("cls");
#elif defined(__linux__) || defined(__unix__) || defined(__APPLE__)
    system("clear");
#endif
    auto screen = ftxui::ScreenInteractive::TerminalOutput();
    auto render = ftxui::Renderer([&] {
        return ftxui::vbox({
            WINDOW_HEADER->Render(),
            ftxui::vbox({
                ftxui::text(WindowMessage) | ftxui::vcenter | ftxui::hcenter
            })
        }) | ftxui::size(ftxui::WIDTH, ftxui::EQUAL, wWidth) | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, wHeight);
    });

    std::thread give_me_a_name{
        [&screen]{
            std::this_thread::sleep_for(std::chrono::seconds(2));
            screen.Exit();
        }
    };

    screen.Loop(render);
}

char TUI::START_SCREEN(const std::size_t &wWidth, const std::size_t &wHeight, std::string& DIRECTORY) {
    std::string input;
    std::string message;
    std::string fmessage;
    std::string dir;
    char result = 0;

    ftxui::ScreenInteractive screen = ftxui::ScreenInteractive::TerminalOutput();

    auto fileAccept = ftxui::Input(&input, "y/n");
    auto dirAccept = ftxui::Input(&dir, DIRECTORY);

    auto accepts = ftxui::Container::Vertical({fileAccept, dirAccept});

    auto render2 = ftxui::Renderer(accepts, [&] {
        return ftxui::vbox({
            ftxui::hbox({
                ftxui::filler(),
                ftxui::text(DICT_GET("TITLE_F1")) | ftxui::center,
                ftxui::filler()
            }) | ftxui::border | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, 5),
            ftxui::vbox({
                ftxui::hcenter(ftxui::text("Loading. . . .")),
                ftxui::filler(),
                ftxui::hcenter(ftxui::text(DICT_GET("LOADSCREEN.LQ"))),
                ftxui::hcenter(fileAccept->Render()),
                ftxui::hcenter(ftxui::text(message)),
                ftxui::filler(),
                ftxui::hcenter(ftxui::text(DICT_GET("file.LOC"))),
                ftxui::hcenter(dirAccept->Render()),
                ftxui::hcenter(ftxui::text(fmessage)),
                ftxui::filler()
            }) | ftxui::border | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, static_cast<int>(wHeight) - 5)
        }) | ftxui::size(ftxui::WIDTH, ftxui::EQUAL, static_cast<int>(wWidth)) | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, static_cast<int>(wHeight));
    });

    auto final_component = ftxui::CatchEvent(render2, [&](const ftxui::Event& event) {
        if (event == ftxui::Event::Return) {
            if (input == "y" || input == "Y" || input == "н" || input == "Н") {
                if (dir.empty()) {
                    try {
                        File::openFile(DIRECTORY);
                    } catch (std::ios::failure &ex) {
                        fmessage = ex.what();
                    } catch (const std::string& msg) {
                        fmessage = msg;
                    }
                } else if (!dir.empty()) {
                    if (dir == DIRECTORY) {
                        try {
                            File::openFile(DIRECTORY);
                        } catch (std::ios::failure &ex) {
                            fmessage = ex.what();
                        } catch (const std::string &msg) {
                            fmessage = msg;
                        }
                    }
                    else {
                        try {
                            File::createFile(dir);
                        } catch (std::ios::failure &ex) {
                            fmessage = ex.what();
                        } catch (const std::string &msg) {
                            fmessage = msg;
                        }
                        return true;
                    }
                }
                result = 'y';
                screen.Exit();
                return true;
            } else if (input == "n" || input == "N" || input == "т" || input == "Т") {
                result = 'n';
                screen.Exit();
                return true;
            } else {
                message = DICT_GET("LOADSCREEN.ERROR.INPUT");
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

void TUI::Employees_LOAD_SCREEN(const std::size_t &wWidth, const std::size_t &wHeight, const std::string& DIRECTORY,
                                std::unordered_map<std::string, std::shared_ptr<Employee>> &STAFF,
                                std::unordered_map<std::string, std::shared_ptr<Project>> &PROJECT_LIST) {

    int TableWidthK{20};
    int TableWidthV{30};


    ftxui::ScreenInteractive screen = ftxui::ScreenInteractive::TerminalOutput();


    std::shared_ptr<ftxui::ComponentBase> render;
    std::shared_ptr<std::string> errorMessage = std::make_shared<std::string>();
    std::string confirmMessage;

    std::queue<TempEmloyee> Emp_buff = File::loadSCV(DIRECTORY);

    auto tempEmp = Emp_buff.front();
    LOCAL::N_A_DEF(tempEmp);

    const auto _POSITION_ = tempEmp.position;

    auto Salary_field = ftxui::Input(&tempEmp.salary, "N/A, int");
    auto NBonus_field = ftxui::Input(&tempEmp.nBonus, "N/A, int");
    auto PoB_field = ftxui::Input(&tempEmp.PoB, "N/A, int");
    auto PADD_field = ftxui::Input(&tempEmp.PADD, "N/A, int");
    auto THeading_field = ftxui::Input(&tempEmp.tHeading, "N/A, int");
    auto Project_field = ftxui::Input(&tempEmp.project, "N/A");


    Salary_field |= ftxui::CatchEvent([&](const ftxui::Event& event){
        return event.is_character() && !std::isdigit(event.character()[0]);
    });
    Salary_field |= ftxui::CatchEvent([&](const ftxui::Event &event) {
       return event.is_character() && tempEmp.salary.size() >= 15;
    });
    Salary_field |= ftxui::CatchEvent([&](const ftxui::Event& event) {
        return event == ftxui::Event::Return;
    });

    NBonus_field |= ftxui::CatchEvent([&](const ftxui::Event& event){
        return event.is_character() && !std::isdigit(event.character()[0]);
    });
    NBonus_field |= ftxui::CatchEvent([&](const ftxui::Event &event) {
        return event.is_character() && tempEmp.nBonus.size() >= 15;
    });
    NBonus_field |= ftxui::CatchEvent([&](const ftxui::Event& event) {
        return event == ftxui::Event::Return;
    });

    PoB_field |= ftxui::CatchEvent([&](const ftxui::Event& event){
        return event.is_character() && !std::isdigit(event.character()[0]);
    });
    PoB_field |= ftxui::CatchEvent([&](const ftxui::Event &event) {
        return event.is_character() && tempEmp.PoB.size() >= 15;
    });
    PoB_field |= ftxui::CatchEvent([&](const ftxui::Event& event) {
        return event == ftxui::Event::Return;
    });

    PADD_field |= ftxui::CatchEvent([&](const ftxui::Event& event){
        return event.is_character() && !std::isdigit(event.character()[0]);
    });
    PADD_field |= ftxui::CatchEvent([&](const ftxui::Event &event) {
        return event.is_character() && tempEmp.PADD.size() >= 15;
    });
    PADD_field |= ftxui::CatchEvent([&](const ftxui::Event& event) {
        return event == ftxui::Event::Return;
    });

    THeading_field |= ftxui::CatchEvent([&](const ftxui::Event& event){
        return event.is_character() && !std::isdigit(event.character()[0]);
    });
    THeading_field |= ftxui::CatchEvent([&](const ftxui::Event &event) {
        return event.is_character() && tempEmp.tHeading.size() >= 15;
    });
    THeading_field |= ftxui::CatchEvent([&](const ftxui::Event& event) {
        return event == ftxui::Event::Return;
    });

    Project_field |= ftxui::CatchEvent([&](const ftxui::Event& event) {
        return event == ftxui::Event::Return;
    });

    auto SelectActiveFieldsGroup1 = [&]{
        std::vector<std::shared_ptr<ftxui::ComponentBase>> ActiveFields;
        ActiveFields.push_back(Salary_field);
        if (_POSITION_ == "cleaner") {}
        else if (_POSITION_ == "driver") ActiveFields.push_back(NBonus_field);
        else  {
            ActiveFields.push_back(PoB_field);
            ActiveFields.push_back(PADD_field);
            if (_POSITION_ == "timtid" || _POSITION_ == "projectm" || _POSITION_ == "seniorm") {
                ActiveFields.push_back(THeading_field);
            }
            ActiveFields.push_back(Project_field);
        }
        return ActiveFields;
    };
    auto ActiveFieldsGroup1 = ftxui::Container::Vertical({SelectActiveFieldsGroup1()});


    auto Input_Salary = Salary_field->Render();
    auto Input_NBonus = NBonus_field->Render();
    auto Input_PoB = PoB_field->Render();
    auto Input_PADD = PADD_field->Render();
    auto Input_THeading = THeading_field->Render();
    auto Input_Project = Project_field->Render();

    auto wSalary = ftxui::Renderer([&]{return ftxui::window(ftxui::text(DICT_GET("personal.Salary")), Salary_field->Render());});
    auto wBonus = ftxui::Renderer([&]{return ftxui::window(ftxui::text(DICT_GET("personal.driver.NightBonus")), NBonus_field->Render());});
    auto wPoB = ftxui::Renderer([&]{return ftxui::window(ftxui::text(DICT_GET("engineer.PartOfBudget")), PoB_field->Render());});
    auto wPADD = ftxui::Renderer([&]{return ftxui::window(ftxui::text(DICT_GET("engineer.ProAdditions")), PADD_field->Render());}) ;
    auto wTHead = ftxui::Renderer([&]{return ftxui::window(ftxui::text(DICT_GET("teamleader.TeamHeading")), THeading_field->Render());});
    auto wProject = ftxui::Renderer([&]{return ftxui::window(ftxui::text(DICT_GET("engineer.Project/s")), Project_field->Render());});


    auto InputFields = [&](const std::string& POSITION) {
        std::vector<ftxui::Component> fields;
        fields.push_back(ftxui::Renderer([&]{return wSalary->Render();}));
        if (POSITION == "cleaner") {}
        else if (POSITION == "driver") {
            fields.push_back(ftxui::Renderer([&]{ return wBonus->Render();}));
        }
        else {
            fields.push_back(ftxui::Renderer([&]{ return wPoB->Render();}));
            fields.push_back(ftxui::Renderer([&] { return wPADD->Render();}));
            if (POSITION == "timlid" || POSITION == "seniorm") fields.push_back(ftxui::Renderer([&] { return wTHead->Render();}));
            fields.push_back(ftxui::Renderer([&] { return wProject->Render();}));
        }
        return ftxui::Renderer([fields = std::move(fields)] {
            std::vector<ftxui::Element> inputs;
            for (auto& el : fields) {
                inputs.push_back(ftxui::hbox({el->Render()}));
                inputs.push_back(ftxui::filler());
            }
            if (!inputs.empty()) inputs.pop_back();
            return ftxui::vbox(std::move(inputs));
        });
    };

    auto InputFieldsView = InputFields(tempEmp.position);

    auto table_rend = ftxui::Renderer([&]{
        TableData table_d = LOCAL::CreateTable(tempEmp);
        std::vector<std::vector<std::string>> rows;
        rows.push_back({fmt::format("{:^{}}", DICT_GET("table.KEY"), TableWidthK),
                        fmt::format("{:^{}}", DICT_GET("table.VALUE"), TableWidthV)});
        for (const auto& [key, value] : table_d) {
            rows.push_back({fmt::format("{:^{}}", key, TableWidthK), fmt::format("{:^{}}", value, TableWidthV)});
        }

        auto TABLE = ftxui::Table(rows);
        TABLE.SelectAll().Border();
        TABLE.SelectAll().SeparatorHorizontal();
        TABLE.SelectAll().SeparatorVertical();

        TABLE.SelectRow(0).Border(ftxui::DOUBLE);
        TABLE.SelectRow(0).Decorate(ftxui::bold);
//        TABLE.SelectRow(0).Decorate(ftxui::color(ftxui::Color::Red));
        TABLE.SelectColumn(0).Decorate(ftxui::bold);

        return TABLE.Render();
    });


    std::function<void()> NextButton_on_click = [&] {
        try {
            LOCAL::N_A_DEL(tempEmp);
        }
        catch (staff::except::IncorrectField& incorrectField) {
            *errorMessage = incorrectField.what_();
            return;
        }
        catch (staff::except::StaffException& staffException) {
            *errorMessage = staffException.what_();
            return;
        }
        catch (std::exception &exception) {
            *errorMessage = exception.what();
            return;
        }
        try {
            Employees::CreateEmployeePointers(tempEmp, STAFF, PROJECT_LIST);
        }
        catch (const staff::except::previouslyAdded& previouslyAdded) {
            *errorMessage = previouslyAdded.what_();
        }
        catch (const staff::except::StaffException& staffException) {
            *errorMessage = staffException.what_();
            return;
        }
        catch (const std::exception& exception) {
            *errorMessage = exception.what();
            return;
        }
        Emp_buff.pop();
        if (Emp_buff.empty()) {
            END_SCREEN(wWidth, wHeight, DICT_GET("LOADSCREEN.END"));
            screen.Exit();
            return;
        }
        tempEmp = Emp_buff.front();
        LOCAL::N_A_DEF(tempEmp);

    };

    auto NextButton = ftxui::Button(DICT_GET("BUTTON.LOAD_SCREEN.nextEmployeeButton"), NextButton_on_click);
    auto NextButtonRender = ftxui::Renderer([&] { return NextButton->Render(); });


    auto AllActiveElements = ftxui::Container::Vertical({ActiveFieldsGroup1, NextButton});

    ///@INFO Render TUI
    render = ftxui::Renderer(AllActiveElements, [&]{
        return ftxui::vbox({
                WINDOW_HEADER->Render(),
            ftxui::hbox({
                ftxui::vbox({
                    ftxui::filler(),
                    ftxui::hbox({ table_rend->Render() | ftxui::hcenter}) | ftxui::hcenter | ftxui::vcenter,
                    ftxui::filler()
                }) | ftxui::size(ftxui::WIDTH, ftxui::EQUAL, static_cast<int>(wWidth) / 2),
                ftxui::separatorDouble(),
                ftxui::vbox({
                    ftxui::hbox({InputFieldsView->Render()| ftxui::vcenter | ftxui::size(ftxui::WIDTH, ftxui::EQUAL, static_cast<int>(wWidth)/2 - 2)}),
                    ftxui::hbox({NextButton->Render() | ftxui::align_right})
                })

            })| ftxui::border | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, static_cast<int>(wHeight) - 4),
        }) | ftxui::size(ftxui::WIDTH, ftxui::EQUAL, static_cast<int>(wWidth));
    });

    auto EVENT = ftxui::CatchEvent(render, [&](const ftxui::Event &event) {
        return false;
    });

    screen.Loop(EVENT);
}
