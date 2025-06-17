add_library(data STATIC
        ../../include/Data/CSV/CSVStaffRepository.h
        CSV/CSVStaffRepository.cpp
        ../../include/Data/CSV/CSVProjectRepository.h
        CSV/CSVProjectRepository.cpp
        ../../include/Data/CSV/CSVSPStorageProvider.h
        CSV/CSVSPStorageProvider.cpp
        ThemeStorageProvider.cpp
        ../../include/Data/ThemeStorageProvider.h
        FileChecking.cpp
        ../../include/Data/FileChecking.h
        TranslationStorageProvider.cpp
        ../../include/Data/TranslationStorageProvider.h
)

target_link_libraries(data PRIVATE interface)
target_link_libraries(data PUBLIC ftxui::screen)
target_link_libraries(data PUBLIC staff utils)

target_include_directories(data PUBLIC ../../include)
