#ifndef GRADE_SERVICE_H
#define GRADE_SERVICE_H

#include "Student.h"
#include <string>
#include <vector>

class GradeService {
public:
    GradeService();

    void initialize(const std::vector<Student>& students);
    Student addStudent(const std::string& name);
    bool assignGrade(int studentId, double grade);
    bool updateGrade(int studentId, double grade);
    std::vector<Student> getAllStudents() const;
    double calculateAverageGrade() const;
    Student* findStudentById(int studentId);
    bool isValidName(const std::string& name) const;
    bool isValidGrade(double grade) const;
    bool hasAssignedGrade(const Student& student) const;

private:
    std::vector<Student> students;
    int nextStudentId;
};

#endif
