cmake_minimum_required(VERSION 3.10)
project(StudentGradeManager CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(student_grade_manager
    src/main.cpp
    src/GradeRepository.cpp
    src/GradeService.cpp
    src/GradeConsole.cpp
)

target_include_directories(student_grade_manager PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src")
