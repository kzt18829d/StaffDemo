#ifndef STAFFDEMO_CSVSPSTORAGEPROVIDER_H
#define STAFFDEMO_CSVSPSTORAGEPROVIDER_H
#include "interaface/ISPStorageProvider.h"
#include <queue>

namespace StaffDemo::Core::StorageProvider {
    class CSVProjectRepository : public Interface::ISPStorageProvider {
    private:
        std::string directory;
    public:
        explicit CSVProjectRepository(const std::string& fileDir);
        ~CSVProjectRepository() override = default;
        std::pair<std::queue<Staff::TempEmloyee>, std::vector<Staff::TempProject>> load() override;
        void save(const std::vector<Staff::TempEmloyee> &staffs, const std::vector<Staff::TempProject> &projects) override;
        void save(const std::map<std::string, std::shared_ptr<Staff::Employee>> &staffs, const std::map<std::string, std::shared_ptr<Staff::Project>> &projects) override;
    };
}


#endif //STAFFDEMO_CSVSPSTORAGEPROVIDER_H
