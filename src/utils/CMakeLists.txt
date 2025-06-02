add_library(utils STATIC
        ../../include/utils/Functions.h
        ../../include/utils/json.hpp
        ../../include/utils/Split.h
        ../../include/utils/StaffExceptions.h
        ../../include/utils/TranslationManager.h
        Functions.cpp
        Split.cpp
        TranslationManager.cpp
)

target_include_directories(utils PUBLIC ../include)

