cmake_minimum_required(VERSION 3.10)
project(HotelManagementSystem CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(hotel_management_system
    src/main.cpp
    src/HotelRepository.cpp
    src/HotelService.cpp
    src/HotelConsole.cpp
)

target_include_directories(hotel_management_system PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src")

configure_file(hotel.json hotel.json COPYONLY)
