#include "TranslationManager.h"
#include <fstream>
#include <iostream>


TranslationManager &TranslationManager::instance() {
    static TranslationManager inst;
    return inst;
}

void TranslationManager::loadJson(const std::string &filename, const std::string &lang) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "~~~~~~ ERROR. FAIL OPEN FILE " << filename << "." << std::endl;
        return;
    }
    try {
        nlohmann::json LANG_DATABASE;
        file >> LANG_DATABASE;
        if (!LANG_DATABASE.contains(lang)) std::cerr << "~~~~~~ ERROR. Language not found." << std::endl;
        translations = LANG_DATABASE[lang];
        localization.clear();
        for (auto& [key, value]: translations.items()) localization[key] = value.get<std::string>();

    }
    catch (const nlohmann::json::parse_error& e) {
        std::cerr << "~~~~~~ ERROR. Parsing JSON: " << e.what() << std::endl;
    }
}

std::string TranslationManager::tr(const std::string &key, bool space, const std::unordered_map<std::string, std::string> &val) {
    auto it = translations.find(key);
    if (it == translations.end()) return "[[" + key + "]]";

    std::string translate = it.value();
    for (const auto& [k, v] : val) {
        std::string placeholder = "{" + k + "}";
        size_t pos;
        while ((pos = translate.find(placeholder)) != std::string::npos) {
            translate.replace(pos, placeholder.length(), v);
        }
    }
    if (space) {
        translate = " " + translate;

    }
    return translate;
}

int TranslationManager::trlen(const std::string &key, size_t modification, const std::unordered_map<std::string, std::string> &val) {
    std::string translate = tr(key, false, val);
    return translate.length() + modification;
}

const std::map<std::string, std::string> &TranslationManager::dict() const {
    return localization;
}


