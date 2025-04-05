#ifndef STAFFDEMO_TRANSLATIONMANAGER_H
#define STAFFDEMO_TRANSLATIONMANAGER_H
#include <string>
#include <fstream>
#include <unordered_map>
#include <nlohmann/json.hpp>

class TranslationManager {
private:
    nlohmann::json translations;
public:
    static TranslationManager& instance();
    void loadJson(const std::string& filename, const std::string& lang);
    std::string tr(const std::string& key, bool space=false, const std::unordered_map<std::string, std::string>& val = {});
    int trlen(const std::string &key, size_t modification, const std::unordered_map<std::string, std::string>& val = {});
};




#endif //STAFFDEMO_TRANSLATIONMANAGER_H
