#include "MainMenu.h"

#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include "CustomLib/TranslationManager.h"

void VIEW_TITLE_FULL() {
    std::cout << fmt::format("{:=^120}", "") << std::endl <<
              fmt::format("{:=^120}", TranslationManager::instance().tr("TITLE1", true) + " ") << std::endl <<
              fmt::format("{:=^120}", TranslationManager::instance().tr("TITLE2", true) + " ") << std::endl <<
              fmt::format("{:=^120}", "") << std::endl << std::endl << std::endl;
}

void loadScreen(std::vector<Employee*> &STAFF) {
    system("cls");
    VIEW_TITLE_FULL();

    if (STAFF.empty()) {
        char agree;
        std::cout << "---- Not founded data about staffs.\n---- Load from file? (y/n): ";
        std::cin >> agree;
        do {
            if (std::cin.fail() || !(agree == 'y' or agree == 'Y' or agree == 'n' or agree == 'N')) {
                std::cerr << std::endl << "~~~~~~ CIN ERROR: INVALID_ARGUMENT. Repeat confirmation. . . ." << std::endl;
                std::cout << "---- Load from file? (y/n): ";
                std::cin >> agree;
            } else break;
        } while(std::cin.fail() || (agree == 'y' or agree == 'Y' or agree == 'n' or agree == 'N'));
//        while (std::cin.fail() || (agree != 'y' || agree != 'Y' || agree != 'n' || agree != 'N')) {
//            std::cerr << "~~~~~~ CIN ERROR: INVALID_ARGUMENT. Repeat confirmation. . . . \n";
//            std::cin.clear();
//            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//            std::cout << "---- Load from file? (y/n): ";
//            std::cin >> agree;
//        }
        switch (agree) {
            case 'N':
            case 'n':
                std::cout << "~~~~~~ The load from the file will not be completed." << std::endl;
                break;
            case 'Y':
            case 'y':
                std::cout << "~~~~~~ Loading from file. . . . .";
                break;
            default:
                break;
        }
    }
    else {
        std::cout << "~~~~~~ Staffs were loaded. . . . ." << std::endl;
    }

}

void Menu_Screen() {
    system("cls");
    VIEW_TITLE_FULL();
    system("pause");
}
