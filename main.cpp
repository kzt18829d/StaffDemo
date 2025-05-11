#include <string>
#include <unordered_map>
#include "Employee.h"
#include "Factory.h"
#include <ftxui/dom/elements.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include "TranslationManager.h"
#include "TUI.h"

static std::size_t WIN_WIDTH = 118;
static std::size_t WIN_HEIGHT = 28;

int main(int argc, char *argv[]){
    std::unordered_map<std::string, std::shared_ptr<Employee>>STAFF;
    std::unordered_multimap<std::string, std::shared_ptr<Project>>PROJECTS;

    TranslationManager::instance().loadJson("./JSON/newLangs.json", "en");

    std::string DIRECTORY("./JSON/Staff_Data.csv");

    switch (auto _load {TUI::START_SCREEN(WIN_WIDTH, WIN_HEIGHT, DIRECTORY)}; _load) {
        case 'y':
            system("cls");
            TUI::LOAD_SCREEN(WIN_WIDTH, WIN_HEIGHT, DIRECTORY, STAFF, PROJECTS);
            break;
        case 'n':
            system("cls");

            break;
        default:
            std::cout << "ERROR" << std::endl;
            break;
    }

    system("pause");
    return EXIT_SUCCESS;
}