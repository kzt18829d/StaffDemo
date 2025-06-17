// Created by hid3h on 18.05.2025.
//

#include "data/CSV/CSVStaffRepository.h"



namespace Data::Repository {
    void CSVStaffRepository::add(std::shared_ptr<Staff::IEmployee> staff) {
        if (STAFF_LIST.contains(staff->getID())) {
            // log
            throw Utils::except::Duplicate(staff->getID() + " уже в списке");
        }
        STAFF_LIST[staff->getID()] = staff;
    }

    void CSVStaffRepository::remove(std::shared_ptr<Staff::IEmployee> staff) {
        if (auto it = std::find_if(STAFF_LIST.begin(), STAFF_LIST.end(), [&](const auto& currStaff){
                return currStaff.second == staff;
        }); it != STAFF_LIST.end()) STAFF_LIST.erase(it);
        else {
            // log
//            throw std::out_of_range("не найден");
        }
    }

    std::map<std::string, std::weak_ptr<Staff::IEmployee>> CSVStaffRepository::getAll() const {
        std::map<std::string, std::weak_ptr<Staff::IEmployee>> temp;
        std::for_each(STAFF_LIST.begin(), STAFF_LIST.end(), [&](const auto& staff){
            temp[staff.first] = staff.second;
        });
        return temp;
    }

    std::map<std::string, std::weak_ptr<Staff::IEmployee>> CSVStaffRepository::getByName(const std::string &name) const {
        std::map<std::string, std::weak_ptr<Staff::IEmployee>> temp;
        std::for_each(STAFF_LIST.begin(), STAFF_LIST.end(), [&](const auto& staff){
            if (staff.second->getName() == name) temp[staff.first] = staff.second; });
        return temp;
    }

    std::map<std::string, std::weak_ptr<Staff::IEmployee>> CSVStaffRepository::getByPosition(const std::string &position) const {
        std::map<std::string, std::weak_ptr<Staff::IEmployee>> temp;
        std::for_each(STAFF_LIST.begin(), STAFF_LIST.end(), [&](const auto& staff){
            if (staff.second->getPosition() == position) temp[staff.first] = staff.second; });
        return temp;
    }

    bool CSVStaffRepository::clean() {
        try {
            STAFF_LIST.clear();
        } catch (...){
            return false;
        }
        if (!STAFF_LIST.empty()) return false;
        return true;
    }
} // StaffRepository