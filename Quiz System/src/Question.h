#ifndef QUESTION_H
#define QUESTION_H

#include <string>
#include <vector>

struct Question {
    int id;
    std::string text;
    std::vector<std::string> options;
    int correctIndex;

    Question() : id(0), correctIndex(-1) {}
    Question(int questionId, const std::string& questionText,
             const std::vector<std::string>& choices, int answerIndex)
        : id(questionId), text(questionText), options(choices), correctIndex(answerIndex) {}
};

#endif
