#include "CustomLib/TranslationManager.h"
#include <QApplication>
#include "ui/MainWindow.h"

int main(int argc, char *argv[]) {

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