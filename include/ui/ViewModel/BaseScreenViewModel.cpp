//
// Created by hid3h on 14.06.2025.
//

#include "BaseScreenViewModel.h"

namespace ViewModel {
    BaseScreenViewModel::BaseScreenViewModel(std::shared_ptr<Core::AppSettings> sharedPtr) : BasicViewModel(sharedPtr), appSettings(sharedPtr) {

    }

    BaseScreenViewModel::~BaseScreenViewModel() {

    }
} // ViewModel