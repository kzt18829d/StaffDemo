#ifndef STAFFDEMO_CSVSPSTORAGEPROVIDER_H
#define STAFFDEMO_CSVSPSTORAGEPROVIDER_H
#include "../../interaface/ISPStorageProvider.h"
#include <queue>

///@defgroup Data

namespace Data::StorageProvider {
    ///@brief Класс для чтения и записи данных через CSV-файл
    ///@param [in,out] directory Расположение CSV-файла
    ///@see ISPStorageProvider
    ///@ingroup Data
    class CSVSPStorageProvider : public Interface::ISPStorageProvider {
    private:
        std::string directory;
    public:
        explicit CSVSPStorageProvider(const std::string& fileDir);
        ~CSVSPStorageProvider() override = default;
        std::pair<std::queue<Staff::TempEmloyee>, std::vector<Staff::TempProject>> load() override; ///< @return std::pair(std::queue, std::vector)
        void save(const std::vector<Staff::TempEmloyee> &staffs, const std::vector<Staff::TempProject> &projects) override;
        void save(const std::map<std::string, std::shared_ptr<Staff::IEmployee>> &staffs, const std::map<std::string, std::shared_ptr<Staff::Project>> &projects) override;
    };
}


#endif //STAFFDEMO_CSVSPSTORAGEPROVIDER_H
