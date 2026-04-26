#include "InputValidator.h"
#include "TaskRepository.h"
#include "TaskService.h"
#include "TodoConsole.h"

int main() {
    TaskRepository repository("tasks.json");
    TaskService service(repository);
    InputValidator validator;
    TodoConsole console(service, validator);
    console.run();
    return 0;
}
