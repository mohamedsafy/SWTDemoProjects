cmake_minimum_required(VERSION 3.10)
project(AppointmentScheduler LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(appointment_scheduler
    src/main.cpp
    src/AppointmentRepository.cpp
    src/SchedulerService.cpp
    src/SchedulerConsole.cpp
)
