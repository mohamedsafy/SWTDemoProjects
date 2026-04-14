#include "CommandConsole.h"
#include "CommandRepository.h"
#include "CommandService.h"
#include <string>

int main() {
    const std::string dataFile = "commands.json";
    CommandRepository repo(dataFile);
    CommandService service(repo);
    CommandConsole console(service);
    console.run();
    return 0;
}
