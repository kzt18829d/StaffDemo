add_library(utils STATIC
        ../../include/utils/Functions.h
        ../../include/utils/json.hpp
        ../../include/utils/Logger.h
        ../../include/utils/Split.h
        ../../include/utils/StaffExceptions.h
        ../../include/utils/TranslationManager.h
        Functions.cpp
        Logger.cpp
        Split.cpp
        StaffExceptions.cpp
        TranslationManager.cpp
)

target_include_directories(utils PUBLIC ../include)