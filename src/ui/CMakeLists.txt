add_library(ui STATIC
        ../../include/ui/components/window_header.h
        ../../include/ui/screens/start_screen.h
        components/window_header.cpp
        screens/start_screen.cpp
        ../../include/ui/buisnessLayer/FieldStrategy.cpp
        ../../include/ui/buisnessLayer/FieldStrategy.h
)

target_link_libraries(ui PUBLIC
        ftxui::screen
        ftxui::dom
        ftxui::component
)
target_include_directories(ui PUBLIC ../include)
