#ifndef STAFFDEMO_TRANSLATIONMANAGER_H
#define STAFFDEMO_TRANSLATIONMANAGER_H
#include <string>
#include <fstream>
#include <unordered_map>
#include "../utils/json.hpp"
#include "Usages.h"

///@namespace Core
namespace Core {
    ///@brief Менеджер переводов
    ///@details Подгружает перевод фраз/слов из JSON для последующего отображения на экране
    ///@ingroup Core
    class TranslationManager {
    private:
        nlohmann::json translations;
        std::map<std::string, std::string> localization;
        Language currentLanguage;
    public:
        TranslationManager(Language& language);
        ~TranslationManager();

        void loadLocalization(nlohmann::json& translation_json);

        std::string tr(const std::string& key, bool space=false, const std::unordered_map<std::string, std::string>& val = {});
        int trlen(const std::string &key, size_t modification, const std::unordered_map<std::string, std::string>& val = {});
        [[nodiscard]] const std::map<std::string, std::string>& dict() const;

    };
}

#endif //STAFFDEMO_TRANSLATIONMANAGER_H
