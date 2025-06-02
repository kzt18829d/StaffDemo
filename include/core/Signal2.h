#ifndef STAFFDEMO_SIGNAL2_H
#define STAFFDEMO_SIGNAL2_H

#include <boost/signals2.hpp>

namespace StaffDemo::Core {
    template<typename ... Args>
    using Signal = boost::signals2::signal<void(Args...)>;
    template<typename T>
    using Slot = boost::signals2::slot<T>;
    template <typename L> //< чё бля, не указывается, но схера ли нужно
    using Connection = boost::signals2::connection;
}

#endif //STAFFDEMO_SIGNAL2_H
