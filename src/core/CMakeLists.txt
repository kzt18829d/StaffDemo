add_library(core STATIC
        ../../include/core/CSVSPStorageProvider.h
        ../../include/core/CSVProjectRepository.h
        ../../include/core/CSVStaffRepository.h
        CSVSPStorageProvider.cpp
        CSVProjectRepository.cpp
        CSVStaffRepository.cpp
)

target_include_directories(core PUBLIC ../../include)