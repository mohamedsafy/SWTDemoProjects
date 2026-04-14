cmake_minimum_required(VERSION 3.10)
project(CommandHistoryManager CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(chm
    src/main.cpp
    src/CommandRepository.cpp
    src/CommandService.cpp
    src/CommandConsole.cpp
)

target_include_directories(chm PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src")
