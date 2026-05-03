#ifndef GRADE_REPOSITORY_H
#define GRADE_REPOSITORY_H

#include "Student.h"
#include <string>
#include <vector>

class GradeRepository {
public:
    explicit GradeRepository(const std::string& filePath = "grades.json");

    std::vector<Student> loadStudents() const;
    void saveStudents(const std::vector<Student>& students) const;
    bool fileExists() const;

private:
    std::string filePath;
};

#endif
