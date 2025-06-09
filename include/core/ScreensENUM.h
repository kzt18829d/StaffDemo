#ifndef STAFFDEMO_SCREENSENUM_H
#define STAFFDEMO_SCREENSENUM_H


///@brief Enum-класс значений окон
///@ingroup Core
enum class WindowType {
    NULL_SCREEN = 0,
    START_WINDOW,
    LOAD_EMPLOYEES_WINDOW_hand,
    LOAD_EMPLOYEES_WINDOW_auto,
    BASE_WINDOW
};

///@brief Enum-класс значений вложенных окон
///@ingroup Core
enum class FrameType {
    BASE,
    Settings,
    SEARCH
};
#endif //STAFFDEMO_SCREENSENUM_H
