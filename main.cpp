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

//int LOAD_EMP_SCREEN(std::unordered_map<std::string, std::unique_ptr<Employee>>&STAFF, std::unordered_multimap<std::string, Project*>&PROJECT_LIST, const std::size_t& wWight, const std::size_t& wHeight) {
//void CREATE_EMPLS_SCREEN(std::unordered_map<std::string, std::unique_ptr<Employee>>&STAFF, std::unordered_multimap<std::string, Project*>&PROJECT_LIST) {


int main(int argc, char *argv[]){
    std::unordered_map<std::string, std::unique_ptr<Employee>>STAFF;
    std::unordered_map<std::string, std::string>POSITION_LIST;
    std::unordered_multimap<std::string, Project*>PROJECT_LIST;

    TranslationManager::instance().loadJson("./JSON/langs.json", "en");

    switch (auto _load {TUI::START_SCREEN(WIN_WIDTH, WIN_HEIGHT)}; _load) {
        case 'y':
            system("cls");
            TUI::LOAD_SCREEN(WIN_WIDTH, WIN_HEIGHT, STAFF, PROJECT_LIST);
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