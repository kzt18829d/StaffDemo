#include "_TUI.h"
#include <sstream>
#include <thread>
#include <chrono>

void _fTUI::fillVoid(const std::string& height, const size_t &width, size_t &curseH, const size_t &MAX_HEIGHT) {
    if (!(height == "max")) throw std::invalid_argument(std::string("_height_ argument don\'t must be" + height));
    while (curseH < MAX_HEIGHT) {
        std::cout << fmt::format("|{:^{}}|", "", width) << "\n";
        ++curseH;
    }
    std::cout << fmt::format("+{:-^{}}+", "", width) << "\n";
}

void _fTUI::fillVoid(std::size_t height, const size_t &width, size_t &curseH, const size_t &MAX_HEIGHT) {
    if (curseH >= MAX_HEIGHT || height == 0) return;
    if (height > MAX_HEIGHT - curseH) height = MAX_HEIGHT - curseH;

    for (std::size_t i = 0; i < height; ++i, ++curseH) {
        std::cout << fmt::format("|{:^{}}|", "", width) << "\n";
    }

    if (curseH == MAX_HEIGHT) {
        std::cout << fmt::format("+{:-^{}}+", "", width) << "\n";
    }
}

void _fTUI::M_TITLE(std::size_t width) {
    std::cout << fmt::format("+{:=^{}}+", Text::mTitle, width) << std::endl;
}

void _fTUI::F_TITLE(std::size_t width) {
    std::cout << fmt::format("+{:=^{}}+", Text::fTitle, width) << std::endl;
}

void _TUI::clean(std::size_t x, std::size_t y) {
    std::stringstream ss;
    std::string str;
    ss << "\033[2J\033[" << x << ";" << y << "H";
    ss >> str;
    std::cout << str;
}

void _TUI::moveCursor(std::size_t row, std::size_t column) {
    std::cout << "\033[" << row << ";" << column << "H";
}

char _TUI::START_SCREEN(const size_t &wWight, const size_t &wHeight) {
    std::size_t curseH = 2;
    _fTUI::M_TITLE(wWight);
    _fTUI::F_TITLE(wWight);

    auto aH = [&curseH](std::size_t h=1) {curseH += h;};
    _fTUI::fillVoid(5, wWight, curseH, wHeight);
    std::cout << fmt::format("|{:^{}}|", "Personal Management System \"StaffDemo\"", wWight) << std::endl;
    std::cout << fmt::format("|{:^{}}|", "Loading. . . .", wWight) << std::endl;
    aH(2);
    _fTUI::fillVoid(5, wWight, curseH, wHeight);
    std::cout << fmt::format("|{:<{}}|", "     Load Database from .scv or create new? (y/n):", wWight) << std::endl;
    aH();
    _fTUI::fillVoid(30, wWight, curseH, wHeight);
    moveCursor(15, 53);

    while (true) {
        switch (auto agree(std::cin.get()); agree) {
            case 'Y':
            case 'y':
                moveCursor(30,1);
                return 'y';
            case 'N':
            case 'n':
                moveCursor(30,1);
                return 'n';
            default:
                moveCursor(16, 35);
                std::cout << "Error, Invalid_Argument. Repeat. . . .";
                std::this_thread::sleep_for(std::chrono::milliseconds(600));
                moveCursor(15, 53);
                std::cout << ' ';
                moveCursor(15, 53);
                break;
        }
    }
}

auto _TUI::LOAD_EMP_SCREEN(const size_t &wWight, const size_t &wHeight,
                          std::unordered_map<std::string, std::unique_ptr<Employee>> &STAFF,
                          std::unordered_multimap<std::string, Project *> &PROJECT_LIST) {
    std::size_t curseH = 2;
    _fTUI::M_TITLE(wWight);
    _fTUI::F_TITLE(wWight);

    auto aH = [&curseH, &wHeight](std::size_t h=1) {curseH += h;};

    _fTUI::fillVoid(2, wWight, curseH, wHeight);
    std::cout << fmt::format("|{:^{}}|", ">>Read file and load<<", wWight); aH();
    _fTUI::fillVoid(2, wWight, curseH, wHeight);
}
