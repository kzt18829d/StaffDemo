//
// Created by hid3h on 14.06.2025.
//

#ifndef STAFFDEMO_BASESCREENVIEWMODEL_H
#define STAFFDEMO_BASESCREENVIEWMODEL_H
#include "BasicViewModel.h"

namespace ViewModel {

    class BaseScreenViewModel : public BasicViewModel {
        std::weak_ptr<Core::AppSettings> appSettings;
    };

} // ViewModel

#endif //STAFFDEMO_BASESCREENVIEWMODEL_H
