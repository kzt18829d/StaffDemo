#ifndef STAFFDEMO_MAINMENU_H
#define STAFFDEMO_MAINMENU_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <limits>
#include "CustomLib/TranslationManager.h"
#include "fmt/core.h"
#include "fmt/format.h"
#include "Headers/Employee.h"


void VIEW_TITLE_FULL();
void loadScreen(std::vector<Employee *> &STAFF);
void Menu_Screen();
#endif //STAFFDEMO_MAINMENU_H
