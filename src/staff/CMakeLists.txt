add_library(staff STATIC
        ../../include/staff/IEmployee.h
        ../../include/staff/employee_temp.h
        ../../include/staff/Engineer.h
        ../../include/staff/Factory.h
        ../../include/staff/Manager.h
        ../../include/staff/Personal.h
        ../../include/staff/StaffInterfaces.h
        Employee.cpp
        Engineer.cpp
        Factory.cpp
        Personal.cpp
        Manager.cpp
        ../../include/staff/staff_enum.h
)

target_include_directories(staff PUBLIC ../include)