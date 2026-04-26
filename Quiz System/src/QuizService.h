#ifndef QUIZ_SERVICE_H
#define QUIZ_SERVICE_H

#include "Question.h"
#include "Result.h"
#include <vector>

class QuizService {
private:
    std::vector<Question> questions;
    Result lastResult;
    bool hasLastResult;

public:
    QuizService();
    void setQuestions(const std::vector<Question>& loadedQuestions);
    bool hasQuestions() const;
    std::vector<Question> getQuestions() const;
    bool validateAnswerChoice(int choice, int optionCount) const;
    Result submitQuiz(const std::vector<int>& answerIndices);
    int calculateScore(const std::vector<int>& answerIndices) const;
    Result buildResult(const std::vector<int>& answerIndices, int score) const;
    bool hasLastScore() const;
    Result getLastResult() const;
};

#endif
