#ifndef RESULT_H
#define RESULT_H

#include "Question.h"
#include <vector>

struct Result {
    std::vector<int> userAnswerIndices;
    int score;
    int totalQuestions;

    Result() : score(0), totalQuestions(0) {}

    int getUserAnswerFor(int questionIndex) const {
        if (questionIndex < 0 || questionIndex >= static_cast<int>(userAnswerIndices.size()))
            return -1;
        return userAnswerIndices[questionIndex];
    }

    int getCorrectAnswerFor(const Question& question) const {
        return question.correctIndex;
    }
};

#endif
