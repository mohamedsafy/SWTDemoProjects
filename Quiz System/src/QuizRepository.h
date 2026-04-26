#ifndef QUIZ_REPOSITORY_H
#define QUIZ_REPOSITORY_H

#include "Question.h"
#include <string>
#include <vector>

class QuizRepository {
private:
    std::string filePath;

public:
    explicit QuizRepository(const std::string& path = "quiz.json");
    std::vector<Question> loadQuestions() const;
    bool fileExists() const;
};

#endif
