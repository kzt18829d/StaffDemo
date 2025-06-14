//
// Created by hid3h on 10.06.2025.
//

#include "loadEmployeeLogModel.h"
#include "fmt/core.h"

namespace Model {
    std::vector<Text> loadEmployeeLogModel::getAllLines_v() const {
        std::vector<Text> tmp;
        for (const auto& line : LogLinesV) tmp.push_back(line);
        return tmp;
    }

    TextLabel loadEmployeeLogModel::getAllLinesFromV() const {
        std::string allLines;
        std::for_each(this->LogLinesV.begin(), this->LogLinesV.end(), [&](const auto& line){
            allLines += line + '\n';
        });
        return allLines;
    }
    TextLabel loadEmployeeLogModel::getAllLinesFromS() const {
        return LogLines;
    }

    Text loadEmployeeLogModel::getLastLine() const {
        return *LogLinesV.rbegin();
    }

    void loadEmployeeLogModel::addLine(Core::InfoType infoType, Text& ID, Text& InfoLine) {
        Text temp = fmt::format("{:<{}}", Core::getInfoTypeByText(infoType), 6) + fmt::format("[ID {:<}]  ", std::move(ID)) + std::move(InfoLine);
        LogLines += temp;
        LogLinesV.push_back(std::move(temp));
    }

    void loadEmployeeLogModel::clean() {
        LogLines.clear();
        LogLinesV.clear();
    }

    ftxui::Element loadEmployeeLogModel::getLogLinesParagraph() {
        auto LogLinesParagraph = ftxui::paragraphAlignLeft(LogLines);
        return LogLinesParagraph;
    }


} // Model