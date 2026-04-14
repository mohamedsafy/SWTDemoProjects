cmake_minimum_required(VERSION 3.15)
project(LibraryManagementSystem)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(LibraryManagementSystem
    src/main.cpp
    src/Models.cpp
    src/LibraryDatabase.cpp
    src/LibraryEngine.cpp
    src/LibraryConsole.cpp
)
