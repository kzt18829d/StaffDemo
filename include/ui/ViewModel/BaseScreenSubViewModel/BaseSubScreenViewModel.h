//
// Created by hid3h on 19.06.2025.
//

#ifndef STAFFDEMO_BASESUBSCREENVIEWMODEL_H
#define STAFFDEMO_BASESUBSCREENVIEWMODEL_H
#include "../BasicViewModel.h"


namespace ViewModel::SubViewModel {

    class BaseSubScreenViewModel : public BasicViewModel {
    private:
        std::weak_ptr<Core::AppSettings> appSettings;

    public:
        explicit BaseSubScreenViewModel(std::shared_ptr<Core::AppSettings> sharedPtr);
        ~BaseSubScreenViewModel();

    };

} // SubViewModel
// ViewModel

#endif //STAFFDEMO_BASESUBSCREENVIEWMODEL_H
