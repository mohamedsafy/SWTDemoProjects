cmake_minimum_required(VERSION 3.10)
project(InventoryManagementSystem CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(inventory_management_system
    src/main.cpp
    src/InventoryRepository.cpp
    src/InventoryService.cpp
    src/InventoryConsole.cpp
)

target_include_directories(inventory_management_system PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src")
