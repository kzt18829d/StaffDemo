#include <string>
#include <unordered_map>
#include <QApplication>
#include "ui/MainWindow.h"
#include "Headers/Employee.h"
#include "Headers/Factory.h"

int main(int argc, char *argv[]){
    std::string id("1uu3uf9");

    std::unordered_map<std::string, std::unique_ptr<Employee>>STAFF;
    std::unordered_map<std::string, std::string>POSITION_LIST;
    std::unordered_multimap<std::string, Project*>PROJECT_LIST;

    QApplication app(argc, argv);
    MainWindow window;
    window.show();
    return app.exec();

//    TranslationManager::instance().loadJson("JSON\\langs.json", "ru");
//
//    std::vector<Employee*> Staff;
//    std::vector<std::pair<Project, std::vector<Employee*>>> projectList; // пока под вопросом
//
//    loadScreen(Staff);
//    system("pause");
//    Menu_Screen();
//
//    bool IS_RUNNING = true;
//    while(IS_RUNNING) {
//
//    }
}