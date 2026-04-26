#include "QuizConsole.h"
#include "QuizRepository.h"
#include "QuizService.h"

int main() {
    QuizRepository repository("quiz.json");
    QuizService service;
    QuizConsole console(service, repository);
    console.run();
    return 0;
}
