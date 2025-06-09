#ifndef STAFFDEMO_BASICVIEWMODEL_H
#define STAFFDEMO_BASICVIEWMODEL_H
#include "boost/signals2.hpp"
#include "../../core/AppSetting.h"
#include "memory"
///@defgroup ViewModel Модели представления

///@namespace ViewModel
namespace ViewModel {

    ///@brief Базовый класс моделей представлений
    ///@ingroup ViewModel
    class BasicViewModel {
    public:
        ~BasicViewModel() = default;
        boost::signals2::signal<void()>ViewUpdateSignal;
    protected:
        std::weak_ptr<Core::AppSettings> appSettings;
        BasicViewModel(std::shared_ptr<Core::AppSettings> sharedPtr) : appSettings(sharedPtr) {}
    public:
        Core::Theme& getTheme() { return this->appSettings.lock()->themeManager->getTheme(); }
        Translate getTranslate(Key key, bool space = false, const std::unordered_map<std::string, std::string>& val = {}) { return this->appSettings.lock()->translationManager->tr(key, space, val);}
    };
}



#endif //STAFFDEMO_BASICVIEWMODEL_H
