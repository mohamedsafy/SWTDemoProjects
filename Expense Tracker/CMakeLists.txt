cmake_minimum_required(VERSION 3.10)
project(ExpenseTracker CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(expense_tracker
    src/main.cpp
    src/ExpenseRepository.cpp
    src/ExpenseService.cpp
    src/ExpenseConsole.cpp
)

target_include_directories(expense_tracker PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src")
