//
// Created by hid3h on 17.06.2025.
//

#include <fstream>
#include "RepositoryInstruments.h"

namespace Core {
    RepositoryInstruments::RepositoryInstruments() {
        staffRepository = std::make_unique<Data::Repository::CSVStaffRepository>();
        projectRepository = std::make_unique<Data::Repository::CSVProjectRepository>();
        storageProvider = std::make_unique<Data::StorageProvider::CSVSPStorageProvider>();
    }

    RepositoryInstruments::~RepositoryInstruments() = default;

    bool RepositoryInstruments::loadPersonalData(Directory &directory) {
        try {
            if (path != directory) path = directory;
            storageProvider->setDirectory(directory);
            auto [queue, vector] = storageProvider->load();
            tempEmployees = std::move(queue);
            tempProjects = std::move(vector);
        } catch (std::exception &ex) {
            return false;
        }
        return true;
    }

    bool RepositoryInstruments::savePersonalData() {
        try {
            storageProvider->setDirectory(path);
            storageProvider->save(staffRepository->getAll(), projectRepository->getProjects());
        } catch (std::exception &ex) {
            return false;
        }
        return true;
    }

    bool RepositoryInstruments::savePersonalData(Directory &directory) {
        try {
            storageProvider->setDirectory(directory);
            storageProvider->save(staffRepository->getAll(), projectRepository->getProjects());
        } catch (std::exception &ex) {
            return false;
        }
        return true;
    }

    bool RepositoryInstruments::createNewPersonalDataWithoutSave() {
        try {
            staffRepository->clean();
            projectRepository->clean();
        } catch (std::exception &ex) {
            return false;
        }
        return true;
    }

    bool RepositoryInstruments::createNewPersonalDataWithSave(Directory &directory) {

        if (!savePersonalData()) {
            return false;
        }

        std::ofstream file(directory);
        try {
            staffRepository->clean();
            projectRepository->clean();
        } catch (std::exception &ex) {
            file.close();
            return false;
        }
        file.close();
        return true;
    }

    bool RepositoryInstruments::createNewPersonalDataWithSave() {
        if (!savePersonalData()) {
            return false;
        }
        std::ofstream file(path);
        if (!file.is_open()) return false;
        try {
            staffRepository->clean();
            projectRepository->clean();
        } catch (std::exception &ex) {
            file.close();
            return false;
        }
        file.close();
        return true;
    }

    bool RepositoryInstruments::createNewPersonalDataWithoutSave(Directory &directory) {
        std::ofstream file(directory);
        if (!file.is_open()) return false;
        try {
            staffRepository->clean();
            projectRepository->clean();
        } catch (std::exception &ex) {
            return false;
        }
        return true;
    }
} // Core