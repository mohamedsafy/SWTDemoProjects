#include "QuizConsole.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace {
bool parseInt(const std::string& input, int& value) {
    std::istringstream stream(input);
    stream >> value;
    return !stream.fail() && stream.eof();
}

std::string readLine() {
    std::string line;
    if (!std::getline(std::cin, line))
        return "";
    return line;
}
}

QuizConsole::QuizConsole(QuizService& serviceRef, QuizRepository& repositoryRef)
    : service(serviceRef), repository(repositoryRef) {}

void QuizConsole::run() {
    initialize();

    while (true) {
        showMenu();
        int choice = readMenuChoice();
        if (choice == 1) {
            startQuiz();
        } else if (choice == 2) {
            viewLastScore();
        } else if (choice == 3) {
            std::cout << "Exiting application.\n";
            break;
        } else {
            std::cout << "Invalid choice. Enter a number from 1 to 3.\n";
        }
    }
}

void QuizConsole::initialize() {
    service.setQuestions(repository.loadQuestions());
    std::cout << "Quiz questions loaded from "
              << (repository.fileExists() ? "existing" : "new")
              << " storage.\n";
}

void QuizConsole::showMenu() const {
    std::cout << "\n--- Quiz System ---\n";
    std::cout << "1. Start Quiz\n";
    std::cout << "2. View Last Score\n";
    std::cout << "3. Exit\n";
    std::cout << "Select option: ";
}

void QuizConsole::startQuiz() {
    if (!service.hasQuestions()) {
        std::cout << "No questions available.\n";
        return;
    }

    std::vector<Question> questions = service.getQuestions();
    std::vector<int> answers;

    for (size_t i = 0; i < questions.size(); ++i) {
        std::cout << "\nQuestion " << (i + 1) << ": " << questions[i].text << "\n";
        for (size_t j = 0; j < questions[i].options.size(); ++j)
            std::cout << (j + 1) << ". " << questions[i].options[j] << "\n";
        answers.push_back(readAnswerChoice(questions[i]));
    }

    Result result = service.submitQuiz(answers);
    std::cout << "\nFinal score: " << result.score << " / "
              << result.totalQuestions << "\n";
    displayReview(result);
}

void QuizConsole::viewLastScore() const {
    if (!service.hasLastScore()) {
        std::cout << "No score recorded yet.\n";
        return;
    }

    Result result = service.getLastResult();
    std::cout << "Last score: " << result.score << " / "
              << result.totalQuestions << "\n";
}

void QuizConsole::displayReview(const Result& result) const {
    std::vector<Question> questions = service.getQuestions();
    std::cout << "\n--- Review Answers ---\n";
    for (size_t i = 0; i < questions.size(); ++i) {
        int userIndex = result.getUserAnswerFor(static_cast<int>(i));
        int correctIndex = result.getCorrectAnswerFor(questions[i]);

        std::cout << questions[i].text << "\n";
        std::cout << "Your answer: ";
        if (service.validateAnswerChoice(userIndex, static_cast<int>(questions[i].options.size())))
            std::cout << questions[i].options[userIndex] << "\n";
        else
            std::cout << "(No answer)\n";

        std::cout << "Correct answer: " << questions[i].options[correctIndex] << "\n";
    }
}

int QuizConsole::readMenuChoice() const {
    int choice = 0;
    std::string line = readLine();
    if (!parseInt(line, choice))
        return 0;
    return choice;
}

int QuizConsole::readAnswerChoice(const Question& question) const {
    while (true) {
        std::cout << "Enter answer choice: ";
        std::string line = readLine();
        int choice = 0;
        if (parseInt(line, choice)) {
            int zeroBased = choice - 1;
            if (service.validateAnswerChoice(zeroBased, static_cast<int>(question.options.size())))
                return zeroBased;
        }
        std::cout << "Invalid answer. Enter a number from 1 to "
                  << question.options.size() << ".\n";
    }
}
