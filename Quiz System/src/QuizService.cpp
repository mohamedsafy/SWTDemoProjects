#include "QuizService.h"

QuizService::QuizService() : hasLastResult(false) {}

void QuizService::setQuestions(const std::vector<Question>& loadedQuestions) {
    questions = loadedQuestions;
}

bool QuizService::hasQuestions() const {
    return !questions.empty();
}

std::vector<Question> QuizService::getQuestions() const {
    return questions;
}

bool QuizService::validateAnswerChoice(int choice, int optionCount) const {
    return choice >= 0 && choice < optionCount;
}

Result QuizService::submitQuiz(const std::vector<int>& answerIndices) {
    int score = calculateScore(answerIndices);
    lastResult = buildResult(answerIndices, score);
    hasLastResult = true;
    return lastResult;
}

int QuizService::calculateScore(const std::vector<int>& answerIndices) const {
    int score = 0;
    size_t count = questions.size();
    if (answerIndices.size() < count)
        count = answerIndices.size();

    for (size_t i = 0; i < count; ++i) {
        if (answerIndices[i] == questions[i].correctIndex)
            ++score;
    }
    return score;
}

Result QuizService::buildResult(const std::vector<int>& answerIndices, int score) const {
    Result result;
    result.userAnswerIndices = answerIndices;
    result.score = score;
    result.totalQuestions = static_cast<int>(questions.size());
    return result;
}

bool QuizService::hasLastScore() const {
    return hasLastResult;
}

Result QuizService::getLastResult() const {
    return lastResult;
}
