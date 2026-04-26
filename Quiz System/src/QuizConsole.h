#ifndef QUIZ_CONSOLE_H
#define QUIZ_CONSOLE_H

#include "Question.h"
#include "QuizRepository.h"
#include "QuizService.h"
#include "Result.h"

class QuizConsole {
private:
    QuizService& service;
    QuizRepository& repository;

public:
    QuizConsole(QuizService& serviceRef, QuizRepository& repositoryRef);
    void run();
    void initialize();
    void showMenu() const;
    void startQuiz();
    void viewLastScore() const;
    void displayReview(const Result& result) const;
    int readMenuChoice() const;
    int readAnswerChoice(const Question& question) const;
};

#endif
