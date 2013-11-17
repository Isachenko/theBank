#pragma once

#include <stdio.h>
#include <string>

class Account
{
public:
    Account(std::string login, std::string password, double money, double percent);
    void increaseMoney();
    void decreaseMoney();
    std::string* getLogin();
    bool checkPassword(std::string* password);
    double getBalance();
private:
    std::string login;
    std::string password;
    double money;
    double percent;
};

