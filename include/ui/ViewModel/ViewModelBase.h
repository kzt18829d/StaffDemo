#ifndef STAFFDEMO_VIEWMODELBASE_H
#define STAFFDEMO_VIEWMODELBASE_H

#include "../../core/Signal2.h"
#include "boost/log/trivial.hpp"
//#include "../../core/ThemeManager.h"


#define LOG_DEBUG BOOST_LOG_TRIVIAL(debug)
#define LOG_INFO  BOOST_LOG_TRIVIAL(info)
#define LOG_WARN  BOOST_LOG_TRIVIAL(warning)
#define LOG_ERROR BOOST_LOG_TRIVIAL(error)
#define LOG_FATAL BOOST_LOG_TRIVIAL(fatal)

namespace StaffDemo::UI {

    class ViewModelBase {
    public:
        ~ViewModelBase();
        Core::Signal<void()> ViewUpdateSignal;
    protected:
        ViewModelBase();
//        const Theme& getCurrentTheme() const {
//            return ThemeManager::instance().getTheme();
//        }
    };

} // UI
// StaffDemo

#endif //STAFFDEMO_VIEWMODELBASE_H
