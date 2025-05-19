add_library(GoogleTests STATIC
        GoogleTests.h
        GoogleTests.cpp
)
target_include_directories(GoogleTests PUBLIC ../Google_Tests)