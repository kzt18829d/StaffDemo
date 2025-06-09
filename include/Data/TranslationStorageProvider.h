//
// Created by hid3h on 09.06.2025.
//

#ifndef STAFFDEMO_TRANSLATIONSTORAGEPROVIDER_H
#define STAFFDEMO_TRANSLATIONSTORAGEPROVIDER_H
#include "../core/Usages.h"
#include "../utils/json.hpp"
#include "fstream"

namespace Data {

    class TranslationStorageProvider {
    private:
        Directory LanguageJsonDirectory;
        nlohmann::json loadedLanguagePack;

    public:
        explicit TranslationStorageProvider(Directory& languageDirectory);
        ~TranslationStorageProvider();

        void loadFromJSON();

        [[nodiscard]] nlohmann::json getLanguagePack();
    };

} // Data

#endif //STAFFDEMO_TRANSLATIONSTORAGEPROVIDER_H
