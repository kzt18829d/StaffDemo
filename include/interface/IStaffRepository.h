#ifndef STAFFDEMO_IUSERREPOSITORY_H
#define STAFFDEMO_IUSERREPOSITORY_H
#include <memory>
#include <map>
#include "../staff/IEmployee.h"

namespace Interface {
    ///@brief Интерфейс репозитория персонала
    ///@details
    ///@ingroup Interface
    class IStaffRepository {
    public:
        virtual ~IStaffRepository() = 0;
        virtual void add(std::shared_ptr<Staff::IEmployee> staff) = 0;
        virtual void remove(std::shared_ptr<Staff::IEmployee> staff) = 0;
        virtual std::map<std::string, std::weak_ptr<Staff::IEmployee>> getAll() const = 0;
        virtual std::map<std::string, std::weak_ptr<Staff::IEmployee>> getByName(const std::string& name) const = 0;
        virtual std::map<std::string, std::weak_ptr<Staff::IEmployee>> getByPosition(const std::string& position) const = 0;
        virtual bool clean() = 0;
    };
}


#endif //STAFFDEMO_IUSERREPOSITORY_H
