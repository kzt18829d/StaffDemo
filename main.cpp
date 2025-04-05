#include <iostream>
#include "Headers/Employee.h"
#include "Headers/Personal.h"
#include "CustomLib/Generators.h"
#include <vector>
#include "CustomLib/TranslationManager.h"
#include <windows.h>

int main() {
    SetConsoleOutputCP( 65001 );
    TranslationManager::instance().loadJson("..\\JSON\\langs.json", "ru");

    std::vector<Employee*> STAFF;
    std::string name = "Stepan";
    Cleaner d1(name, 100, 100);
    d1.printInfo();
    d1.calc();
    d1.printInfo();
}