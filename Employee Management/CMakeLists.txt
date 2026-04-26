cmake_minimum_required(VERSION 3.10)
project(EmployeeManagement CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(employee_management
    src/main.cpp
    src/EmployeeRepository.cpp
    src/EmployeeService.cpp
    src/EmployeeConsole.cpp
)

target_include_directories(employee_management PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src")
