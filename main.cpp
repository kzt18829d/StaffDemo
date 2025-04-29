#include <string>
#include <unordered_map>
#include <QApplication>
#include "ui/MainWindow.h"
#include "Headers/Employee.h"
#include "Headers/Factory.h"
#include "Graphics.h"
#include <thread>
#include <chrono>
#include "CustomLib/Functions.h"

std::size_t WIN_WIDTH = 118;
std::size_t WIN_HEIGHT = 28;


void fillVoid(const std::string height, const std::size_t& width, std::size_t& curseH, const std::size_t& MAX_HEIGHT) {
    if (!(height == "max")) throw std::invalid_argument(std::string("_height_ argument don\'t must be" + height));
    while (curseH < MAX_HEIGHT) {
        std::cout << fmt::format("|{:^{}}|", "", width) << "\n";
        ++curseH;
    }

    std::cout << fmt::format("+{:-^{}}+", "", width) << "\n";
}
void fillVoid(std::size_t height, const std::size_t& width, std::size_t& curseH, const std::size_t& MAX_HEIGHT) {
    if (curseH >= MAX_HEIGHT || height == 0) return;
    if (height > MAX_HEIGHT - curseH) height = MAX_HEIGHT - curseH;

    for (std::size_t i = 0; i < height; ++i, ++curseH) {
        std::cout << fmt::format("|{:^{}}|", "", width) << "\n";
    }

    if (curseH == MAX_HEIGHT) {
        std::cout << fmt::format("+{:-^{}}+", "", width) << "\n";
    }
}

void moveCoursor(std::size_t y, std::size_t x) {
    std::cout << "\033[" << y << ";" << x << "H";
}
void clean(std::size_t x=1, std::size_t y=1) {
    std::stringstream ss;
    std::string str;
    ss << "\033[2J\033[" << x << ";" << y << "H";
    ss >> str;
    std::cout << str;
}

char START_SCREEN(const std::size_t& wWight, const std::size_t& wHeight) {
    std::size_t curseH = 2;
    M_TITLE(wWight);
    F_TITLE(wWight);

    fillVoid(5, wWight, curseH, wHeight);
    std::cout << fmt::format("|{:^{}}|", "Personal Management System \"StaffDemo\"", wWight) << std::endl;
    std::cout << fmt::format("|{:^{}}|", "Loading. . . .", wWight) << std::endl;
    ++curseH;
    ++curseH;
    fillVoid(5, wWight, curseH, wHeight);
    std::cout << fmt::format("|{:<{}}|", "     Load Database from .scv or create new? (y/n):", wWight) << std::endl;
    ++curseH;
    fillVoid(30, wWight, curseH, wHeight);
    moveCoursor(15, 53);

    while (true) {
        switch (auto agree(std::cin.get()); agree) {
            case 'Y':
            case 'y':
                moveCoursor(30,1);
                return 'y';
            case 'N':
            case 'n':
                moveCoursor(30,1);
                return 'n';
            default:
                moveCoursor(16, 35);
                std::cout << "Error, Invalid_Argument. Repeat. .";
                std::this_thread::sleep_for(std::chrono::milliseconds(1200));
                moveCoursor(15, 53);
                std::cout << ' ';
                moveCoursor(15, 53);
                break;
        }
    }
}

int LOAD_EMP_SCREEN(std::unordered_map<std::string, std::unique_ptr<Employee>>&STAFF, std::unordered_multimap<std::string, Project*>&PROJECT_LIST) {
    return 0;
}

void CREATE_EMPLS_SCREEN(std::unordered_map<std::string, std::unique_ptr<Employee>>&STAFF, std::unordered_multimap<std::string, Project*>&PROJECT_LIST) {

}

int main(int argc, char *argv[]){
    std::string id("1uu3uf9");

    std::unordered_map<std::string, std::unique_ptr<Employee>>STAFF;
    std::unordered_map<std::string, std::string>POSITION_LIST;
    std::unordered_multimap<std::string, Project*>PROJECT_LIST;

    switch (START_SCREEN(WIN_WIDTH, WIN_HEIGHT)) {
        case 'y':
            try {
                LOAD_EMP_SCREEN(STAFF, PROJECT_LIST);
            }
            catch (...) {

            }
        case 'n':
            try{
                CREATE_EMPLS_SCREEN(STAFF, PROJECT_LIST);
            }
            catch (...) {

            }
    };
    system("pause");

//    QApplication app(argc, argv);
//    MainWindow window;
//    window.show();
//    return app.exec();

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