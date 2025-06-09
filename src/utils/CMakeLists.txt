add_library(utils STATIC
        ../../include/utils/Functions.h
        ../../include/utils/json.hpp
        ../../include/utils/Split.h
        ../../include/utils/StaffExceptions.h
        ../../include/core/TranslationManager.h
        Functions.cpp
        Split.cpp
        ../core/TranslationManager.cpp
        ../../include/utils/FileTimeStamp.h
)

target_include_directories(utils PUBLIC ../include)

