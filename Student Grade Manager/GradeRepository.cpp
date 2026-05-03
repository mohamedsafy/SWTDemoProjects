#include "GradeRepository.h"
#include "json.hpp"
#include <fstream>

using json = nlohmann::json;

GradeRepository::GradeRepository(const std::string& path) : filePath(path) {}

std::vector<Student> GradeRepository::loadStudents() const {
    std::vector<Student> students;
    std::ifstream input(filePath.c_str());
    if (!input) {
        return students;
    }

    try {
        json data;
        input >> data;
        if (!data.contains("students") || !data["students"].is_array()) {
            return students;
        }

        for (size_t i = 0; i < data["students"].size(); ++i) {
            const json& item = data["students"][i];
            if (!item.contains("id") || !item.contains("name")) {
                continue;
            }

            Student student;
            student.id = item["id"].get<int>();
            student.name = item["name"].get<std::string>();
            student.grade = item.value("grade", 0.0);
            student.gradeAssigned = item.value("gradeAssigned", item.contains("grade"));
            students.push_back(student);
        }
    } catch (...) {
        students.clear();
    }

    return students;
}

void GradeRepository::saveStudents(const std::vector<Student>& students) const {
    json data;
    data["students"] = json::array();

    for (size_t i = 0; i < students.size(); ++i) {
        json item;
        item["id"] = students[i].id;
        item["name"] = students[i].name;
        item["grade"] = students[i].grade;
        item["gradeAssigned"] = students[i].gradeAssigned;
        data["students"].push_back(item);
    }

    std::ofstream output(filePath.c_str());
    output << data.dump(2);
}

bool GradeRepository::fileExists() const {
    std::ifstream input(filePath.c_str());
    return input.good();
}
