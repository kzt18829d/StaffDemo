add_library(data STATIC
        ../../include/data/CSV/CSVStaffRepository.h
        CSV/CSVStaffRepository.cpp
        ../../include/data/CSV/CSVProjectRepository.h
        CSV/CSVProjectRepository.cpp
        ../../include/data/CSV/CSVSPStorageProvider.h
        CSV/CSVSPStorageProvider.cpp
)

target_include_directories(data PUBLIC ../../include)
