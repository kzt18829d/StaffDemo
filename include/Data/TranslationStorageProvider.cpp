//
// Created by hid3h on 09.06.2025.
//

#include "TranslationStorageProvider.h"
#include "iostream"

namespace Data {
    TranslationStorageProvider::TranslationStorageProvider(Directory &languageDirectory) {
        this->LanguageJsonDirectory = languageDirectory;
    }

    TranslationStorageProvider::~TranslationStorageProvider() = default;

    void TranslationStorageProvider::loadFromJSON() {
        std::ifstream JSON(this->LanguageJsonDirectory, std::ios::in);

        if (!JSON.is_open()) {
            std::cerr << "~~~~~~ ERROR. FAIL OPEN FILE " << this->LanguageJsonDirectory << "." << std::endl;
            return;
        }
        try {
            JSON >> this->loadedLanguagePack;
        } catch (std::exception &ex) {
            throw ex.what();
        }
    }

    nlohmann::json TranslationStorageProvider::getLanguagePack() {
        return this->loadedLanguagePack;
    }
} // Data