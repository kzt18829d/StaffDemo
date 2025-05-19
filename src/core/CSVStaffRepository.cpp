// Created by hid3h on 18.05.2025.
//

#include "../../include/core/CSVStaffRepository.h"



namespace StaffDemo::Core::StaffRepository {
    void CSVStaffRepository::add(std::shared_ptr<StaffDemo::Core::Staff::Employee> staff) {
        if (STAFF_LIST.contains(staff->getID())) {
            // log
            throw StaffDemo::Utils::except::Duplicate(staff->getID() + " уже в списке");
        }
        STAFF_LIST[staff->getID()] = staff;
    }

    void CSVStaffRepository::remove(std::shared_ptr<StaffDemo::Core::Staff::Employee> staff) {
        if (auto it = std::find_if(STAFF_LIST.begin(), STAFF_LIST.end(), [&](const auto& currStaff){
                return currStaff.second == staff;
        }); it != STAFF_LIST.end()) STAFF_LIST.erase(it);
        else {
            // log
            throw std::out_of_range("не найден");
        }
    }

    std::map<std::string, std::weak_ptr<StaffDemo::Core::Staff::Employee>> CSVStaffRepository::getAll() const {
        std::map<std::string, std::weak_ptr<StaffDemo::Core::Staff::Employee>> temp;
        std::for_each(STAFF_LIST.begin(), STAFF_LIST.end(), [&](const auto& staff){
            temp[staff.first] = staff.second;
        });
        return temp;
    }

    std::map<std::string, std::weak_ptr<StaffDemo::Core::Staff::Employee>> CSVStaffRepository::getByName(const std::string &name) const {
        std::map<std::string, std::weak_ptr<StaffDemo::Core::Staff::Employee>> temp;
        std::for_each(STAFF_LIST.begin(), STAFF_LIST.end(), [&](const auto& staff){
            if (staff.second->getName() == name) temp[staff.first] = staff.second; });
        return temp;
    }

    std::map<std::string, std::weak_ptr<StaffDemo::Core::Staff::Employee>> CSVStaffRepository::getByPosition(const std::string &position) const {
        std::map<std::string, std::weak_ptr<StaffDemo::Core::Staff::Employee>> temp;
        std::for_each(STAFF_LIST.begin(), STAFF_LIST.end(), [&](const auto& staff){
            if (staff.second->getPosition() == position) temp[staff.first] = staff.second; });
        return temp;
    }
} // StaffRepository