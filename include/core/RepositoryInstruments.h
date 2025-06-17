//
// Created by hid3h on 17.06.2025.
//

#ifndef STAFFDEMO_REPOSITORYINSTRUMENTS_H
#define STAFFDEMO_REPOSITORYINSTRUMENTS_H

#include <memory>
#include "Usages.h"

#include "../Data/CSV/CSVStaffRepository.h"
#include "../Data/CSV/CSVProjectRepository.h."
#include "../Data/CSV/CSVSPStorageProvider.h"


namespace Core {

    class RepositoryInstruments {
    private:
        Directory path;
        [[maybe_unused]] Directory path2;
        std::unique_ptr<Data::StorageProvider::CSVSPStorageProvider> storageProvider;
        std::queue<Staff::TempEmloyee> tempEmployees;
        std::vector<Staff::TempProject> tempProjects;

    public:
        std::unique_ptr<Data::Repository::CSVStaffRepository> staffRepository;
        std::unique_ptr<Data::Repository::CSVProjectRepository> projectRepository;

        RepositoryInstruments();
        ~RepositoryInstruments();

        bool loadPersonalData(Directory& directory);
        bool savePersonalData();
        bool savePersonalData(Directory& directory);
        bool createNewPersonalDataWithoutSave();
        bool createNewPersonalDataWithoutSave(Directory& directory);
        bool createNewPersonalDataWithSave(Directory& directory);
        bool createNewPersonalDataWithSave();

    };

} // Core

#endif //STAFFDEMO_REPOSITORYINSTRUMENTS_H
