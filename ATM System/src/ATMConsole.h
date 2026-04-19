#ifndef ATM_CONSOLE_H
#define ATM_CONSOLE_H

#include "ATMEngine.h"

class ATMConsole {
private:
    ATMEngine engine;

public:
    void consoleInterfaceStart(void);
    void consoleWithdrawMenu(void);
    void consoleDepositMenu(void);
    void consoleTransLogsMenu(void);
};

#endif
