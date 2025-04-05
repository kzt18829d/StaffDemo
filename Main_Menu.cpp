#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <limits>
#include "CustomLib/TranslationManager.h"

template <typename T>
void load(const std::vector<T*>& STAFF) {
    system("cls");
    std::cout << std::setfill('=') << std::setw(50) << TranslationManager::instance().tr("TITLE_F") << std::setw(50 - 37) << "" << std::endl;
    std::cout << std::setw(50) << " Main Menu " << std::setw(39) << "" << std::endl << std::setfill(' ');

    if (STAFF.empty()) {
        char agree;
        std::cout << "---- Not founded data about staffs.\n---- Load from file? (y/n): ";
        std::cin >> agree;
        while (std::cin.fail() || (agree != 'y' || agree != 'Y' || agree != 'n' || agree != 'N')) {
            std::cerr << "~~~~~~ CIN ERROR: INVALID_ARGUMENT. Repeat confirmation. . . . " << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "---- Load from file? (y/n): ";
            std::cin >> agree;
        }
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


}