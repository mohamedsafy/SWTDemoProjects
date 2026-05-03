#include "GradeConsole.h"
#include <iomanip>
#include <iostream>
#include <sstream>

static std::string readLine() {
    std::string line;
    if (!std::getline(std::cin, line)) {
        return "";
    }
    return line;
}

static bool parseInt(const std::string& input, int& value) {
    std::istringstream stream(input);
    stream >> value;
    return !stream.fail() && stream.eof();
}

static bool parseDouble(const std::string& input, double& value) {
    std::istringstream stream(input);
    stream >> value;
    return !stream.fail() && stream.eof();
}

GradeConsole::GradeConsole(GradeService& svc, GradeRepository& repo)
    : service(svc), repository(repo) {}

void GradeConsole::initializeSystem() {
    service.initialize(repository.loadStudents());
}

void GradeConsole::run() {
    initializeSystem();

    for (;;) {
        int option = showMenu();
        if (option == 1) {
            addStudent();
        } else if (option == 2) {
            assignGrade();
        } else if (option == 3) {
            updateGrade();
        } else if (option == 4) {
            viewStudentGrades();
        } else if (option == 5) {
            calculateAverageGrade();
        } else if (option == 6) {
            displayMessage("Goodbye.");
            break;
        } else {
            displayMessage("Invalid choice. Enter 1-6.");
        }
    }
}

int GradeConsole::showMenu() {
    std::cout << "\n--- Student Grade Manager ---\n";
    std::cout << "1. Add Student\n";
    std::cout << "2. Assign Grade\n";
    std::cout << "3. Update Grade\n";
    std::cout << "4. View Student Grades\n";
    std::cout << "5. Calculate Average Grade\n";
    std::cout << "6. Exit\n";
    std::cout << "Select option: ";

    int option = 0;
    if (!parseInt(readLine(), option)) {
        return 0;
    }
    return option;
}

void GradeConsole::addStudent() {
    std::string name = readStudentName();
    Student student = service.addStudent(name);
    if (student.id == 0) {
        displayMessage("Invalid name. Student was not added.");
        return;
    }

    repository.saveStudents(service.getAllStudents());
    std::cout << "Student added with ID: " << student.id << "\n";
}

void GradeConsole::assignGrade() {
    int id = readStudentId();
    double grade = readGrade();
    if (!service.assignGrade(id, grade)) {
        displayMessage("Assignment failed. Check student ID and grade range 0-100.");
        return;
    }

    repository.saveStudents(service.getAllStudents());
    displayMessage("Grade assigned and saved.");
}

void GradeConsole::updateGrade() {
    int id = readStudentId();
    double grade = readGrade();
    if (!service.updateGrade(id, grade)) {
        displayMessage("Update failed. Check student ID and grade range 0-100.");
        return;
    }

    repository.saveStudents(service.getAllStudents());
    displayMessage("Grade updated and saved.");
}

void GradeConsole::viewStudentGrades() {
    std::vector<Student> students = service.getAllStudents();
    if (students.empty()) {
        displayMessage("(No students found.)");
        return;
    }

    for (size_t i = 0; i < students.size(); ++i) {
        std::cout << "ID: " << students[i].id << "  Name: " << students[i].name << "  Grade: ";
        if (students[i].gradeAssigned) {
            std::cout << std::fixed << std::setprecision(2) << students[i].grade;
        } else {
            std::cout << "Unassigned";
        }
        std::cout << "\n";
    }
}

void GradeConsole::calculateAverageGrade() {
    double average = service.calculateAverageGrade();
    if (average < 0.0) {
        displayMessage("No assigned grades available.");
        return;
    }

    std::cout << "Average grade: " << std::fixed << std::setprecision(2) << average << "\n";
}

std::string GradeConsole::readStudentName() {
    std::cout << "Enter student name: ";
    return readLine();
}

int GradeConsole::readStudentId() {
    std::cout << "Enter student ID: ";
    int id = 0;
    if (!parseInt(readLine(), id)) {
        return 0;
    }
    return id;
}

double GradeConsole::readGrade() {
    std::cout << "Enter grade (0-100): ";
    double grade = -1.0;
    if (!parseDouble(readLine(), grade)) {
        return -1.0;
    }
    return grade;
}

void GradeConsole::displayMessage(const std::string& message) {
    std::cout << message << "\n";
}
