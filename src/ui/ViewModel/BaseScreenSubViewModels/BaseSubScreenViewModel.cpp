//
// Created by hid3h on 19.06.2025.
//

#include "ui/ViewModel/BaseScreenSubViewModel/BaseSubScreenViewModel.h"


namespace ViewModel::SubViewModel {
    BaseSubScreenViewModel::BaseSubScreenViewModel(std::shared_ptr<Core::AppSettings> sharedPtr) : BasicViewModel(sharedPtr), appSettings(sharedPtr){

    }

    BaseSubScreenViewModel::~BaseSubScreenViewModel() {

    }
} // SubViewModel
// ViewModel