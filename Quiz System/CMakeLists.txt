cmake_minimum_required(VERSION 3.10)
project(QuizSystem CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(quiz_system
    src/main.cpp
    src/QuizRepository.cpp
    src/QuizService.cpp
    src/QuizConsole.cpp
)

target_include_directories(quiz_system PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src")
