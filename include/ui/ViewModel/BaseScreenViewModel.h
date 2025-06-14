//
// Created by hid3h on 14.06.2025.
//

#ifndef STAFFDEMO_BASESCREENVIEWMODEL_H
#define STAFFDEMO_BASESCREENVIEWMODEL_H
#include "BasicViewModel.h"

namespace ViewModel {

    class BaseScreenViewModel : public BasicViewModel {
    private:
        std::weak_ptr<Core::AppSettings> appSettings;

    public:
        BaseScreenViewModel(std::shared_ptr<Core::AppSettings> sharedPtr);
        ~BaseScreenViewModel();
        boost::signals2::signal<void()> exitSignal;


    };

} // ViewModel

#endif //STAFFDEMO_BASESCREENVIEWMODEL_H
