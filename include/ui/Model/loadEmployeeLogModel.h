//
// Created by hid3h on 10.06.2025.
//

#ifndef STAFFDEMO_LOADEMPLOYEELOGMODEL_H
#define STAFFDEMO_LOADEMPLOYEELOGMODEL_H
#include "vector"
#include "string"
#include "../../core/Usages.h"
#include "../../core/InfoTypeENUM.h"
#include "algorithm"
#include "ftxui/component/component.hpp"

namespace Model {

    class loadEmployeeLogModel {
    private:
        std::vector<Text> LogLinesV;
        std::string LogLines;

    public:
        std::vector<Text> getAllLines_v() const;
        TextLabel getAllLinesFromV() const;
        TextLabel getAllLinesFromS() const;
        Text getLastLine() const;
        void addLine(Core::InfoType infoType, Text& ID, Text& InfoLine);
        void clean();
        ftxui::Element getLogLinesParagraph();
    };

} // Model

#endif //STAFFDEMO_LOADEMPLOYEELOGMODEL_H
