cmake_minimum_required(VERSION 3.10)
project(ContactManager CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(contact_manager
    src/main.cpp
    src/ContactRepository.cpp
    src/ContactService.cpp
    src/ContactConsole.cpp
)

target_include_directories(contact_manager PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src")
