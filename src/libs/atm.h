#pragma once
#include "account.h"
#include "bank.h"

class ATM
{
public:
    ATM();
    void start();
private:
    Bank bank;
    void balanceAccess();
};
