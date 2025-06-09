#ifndef STAFFDEMO_FILETIMESTAMP_H
#define STAFFDEMO_FILETIMESTAMP_H

///@defgroup Utils Утилиты


///@namespace Utils
namespace Utils {

    ///@brief Функция-TimeStamp
    ///@details Используется для получения текущей даты-времени для создаваемых файлов, если таковыми требуется
    ///@ingroup Utils
    inline std::string getTime() {
        const time_t now = time(nullptr);
        std::string time_str = ctime(&now);

        if (!time_str.empty() && time_str.back() == '\n') {
            time_str.pop_back();
        }

        std::replace(time_str.begin(), time_str.end(), ' ', '_');
        std::replace(time_str.begin(), time_str.end(), ':', '-');

        return time_str;
    }

}

#endif //STAFFDEMO_FILETIMESTAMP_H
