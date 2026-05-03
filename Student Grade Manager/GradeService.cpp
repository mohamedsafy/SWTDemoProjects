#include "GradeService.h"

GradeService::GradeService() : nextStudentId(1) {}

void GradeService::initialize(const std::vector<Student>& loadedStudents) {
    students = loadedStudents;
    nextStudentId = 1;
    for (size_t i = 0; i < students.size(); ++i) {
        if (students[i].id >= nextStudentId) {
            nextStudentId = students[i].id + 1;
        }
    }
}

Student GradeService::addStudent(const std::string& name) {
    Student student;
    student.id = 0;
    student.name = "";
    student.grade = 0.0;
    student.gradeAssigned = false;

    if (!isValidName(name)) {
        return student;
    }

    student.id = nextStudentId++;
    student.name = name;
    students.push_back(student);
    return student;
}

bool GradeService::assignGrade(int studentId, double grade) {
    Student* student = findStudentById(studentId);
    if (student == 0 || !isValidGrade(grade)) {
        return false;
    }

    student->grade = grade;
    student->gradeAssigned = true;
    return true;
}

bool GradeService::updateGrade(int studentId, double grade) {
    return assignGrade(studentId, grade);
}

std::vector<Student> GradeService::getAllStudents() const {
    return students;
}

double GradeService::calculateAverageGrade() const {
    double total = 0.0;
    int count = 0;

    for (size_t i = 0; i < students.size(); ++i) {
        if (hasAssignedGrade(students[i])) {
            total += students[i].grade;
            ++count;
        }
    }

    if (count == 0) {
        return -1.0;
    }
    return total / count;
}

Student* GradeService::findStudentById(int studentId) {
    for (size_t i = 0; i < students.size(); ++i) {
        if (students[i].id == studentId) {
            return &students[i];
        }
    }
    return 0;
}

bool GradeService::isValidName(const std::string& name) const {
    for (size_t i = 0; i < name.size(); ++i) {
        if (name[i] != ' ' && name[i] != '\t') {
            return true;
        }
    }
    return false;
}

bool GradeService::isValidGrade(double grade) const {
    return grade >= 0.0 && grade <= 100.0;
}

bool GradeService::hasAssignedGrade(const Student& student) const {
    return student.gradeAssigned;
}
