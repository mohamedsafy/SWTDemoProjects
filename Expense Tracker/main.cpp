#include "ExpenseConsole.h"
#include "ExpenseRepository.h"
#include "ExpenseService.h"
#include <string>

int main() {
    const std::string dataFile = "expenses.json";
    ExpenseRepository repo(dataFile);
    ExpenseService service(repo);
    ExpenseConsole console(service);
    console.run();
    return 0;
}
