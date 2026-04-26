#include "GradeConsole.h"

int main() {
    GradeRepository repository;
    GradeService service;
    GradeConsole console(service, repository);
    console.run();
    return 0;
}
