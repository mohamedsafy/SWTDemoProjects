#include "EmployeeConsole.h"
#include "EmployeeRepository.h"
#include "EmployeeService.h"
#include <string>

int main() {
    const std::string dataFile = "employees.json";
    EmployeeRepository repo(dataFile);
    EmployeeService service(repo);
    EmployeeConsole console(service);
    console.run();
    return 0;
}
