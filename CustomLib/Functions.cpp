#include "Functions.h"

const std::string SYMBOLS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefjhijklmnopqrstuvwxyz0123456789";
const std::string NUMBERS = "0123456789";

std::random_device rd;
std::mt19937 gen(rd());

std::string genid() { // generate id without parameters
    std::uniform_int_distribution<> dist(0, SYMBOLS.size()-1);
    std::string id;
    for (int i = 0; i < 10; ++i) id += SYMBOLS[dist(gen)];
    return id;
}

std::string genid(int lenght, bool num_token, bool let_token) { // generate id with parameters
    std::string id;
    size_t gen_type;

    std::uniform_int_distribution<> dist(0, SYMBOLS.size()-1);
    if ((!num_token && !let_token) || (num_token && let_token)) { gen_type = 0; }
    else if (!num_token) { dist = std::uniform_int_distribution<> (0, SYMBOLS.size() - 11); gen_type = 1; }
    else { dist = std::uniform_int_distribution<> (0, NUMBERS.size() - 1); gen_type = 2; }

    switch (gen_type) {
        case 0:
        case 1:
            for (int i{0}; i < lenght; i++) id += SYMBOLS[dist(gen)];
            break;
        case 2:
            for (int i{0}; i < lenght; i++) id += NUMBERS[dist(gen)];
            break;
    }
    return id;
}