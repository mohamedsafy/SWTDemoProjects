cmake_minimum_required(VERSION 3.10)
project(TodoList CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(todo_list
    src/main.cpp
    src/TaskRepository.cpp
    src/TaskService.cpp
    src/TodoConsole.cpp
)

target_include_directories(todo_list PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src")
