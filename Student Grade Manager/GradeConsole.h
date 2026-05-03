#ifndef GRADE_CONSOLE_H
#define GRADE_CONSOLE_H

#include "GradeRepository.h"
#include "GradeService.h"
#include <string>

class GradeConsole {
public:
    GradeConsole(GradeService& service, GradeRepository& repository);

    void initializeSystem();
    void run();
    int showMenu();
    void addStudent();
    void assignGrade();
    void updateGrade();
    void viewStudentGrades();
    void calculateAverageGrade();
    std::string readStudentName();
    int readStudentId();
    double readGrade();
    void displayMessage(const std::string& message);

private:
    GradeService& service;
    GradeRepository& repository;
};

#endif
