#pragma once

#include <stdio.h>
#include <string>
#include <time.h>

class Account
{
public:
    Account(std::string login, std::string password, double money);
    double putMoney(double money);
    virtual double withdrawMoney(double money);
    double getBalance();
    std::string* getLogin();
    bool checkPassword(std::string* password);
    ~Account();
protected:
    std::string login;
    std::string password;
    double money;
};

class SaveAccount : public Account
{
public:
    SaveAccount(std::string login, std::string password, double money, double percent);
    void increaseMoney();
private:
    double percent;
};

class TimedMaturityAccount : public SaveAccount
{
public:
    TimedMaturityAccount(std::string login, std::string password, double money, double percent, double penalty, int term);
    double withdrawMoney(double money) override;
private:
    double penalty;
    int term;
};

class CheckingAccount : public Account
{
public:
    CheckingAccount(std::string login, std::string password, double money, double fee, int quota);
    double withdrawMoney(double money) override;
private:
    double fee;
    int quota;
    int curWithdrawCount;
};

class OverdraftAccount : public Account
{
public:
    OverdraftAccount(std::string login, std::string password, double money, double penalty);
    double withdrawMoney(double money) override;
    double decreaseMoney();
private:
    double penalty;
};

