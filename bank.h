#pragma once

#include <stdio.h>
#include <vector>
#include <account.h>

class Account;

class Bank
{
public:
    Bank();
    void addAccount(Account* account);
    Account* getByLoginPassword(std::string* login, std::string* password);
private:
    std::vector<Account*> accounts;
};

