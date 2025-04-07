#include <iostream>
#include "Headers/Employee.h"
#include <unordered_map>
#include "CustomLib/TranslationManager.h"
#include "MainMenu.h"
#include "Headers/Factory.h"

int main() {
    TranslationManager::instance().loadJson("JSON\\langs.json", "ru");

    std::vector<Employee*> Staff;
    std::vector<std::pair<Project, std::vector<Employee*>>> projectList; // пока под вопросом

    loadScreen(Staff);
    system("pause");
    Menu_Screen();

    bool IS_RUNNING = true;
    while(IS_RUNNING) {

    }
}