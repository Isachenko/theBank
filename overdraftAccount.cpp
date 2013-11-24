#include "account.h"

OverdraftAccount::OverdraftAccount(std::string login, std::string password, double money, double penalty):
    Account(login, password, money){
    this->penalty = penalty;
}

double OverdraftAccount::withdrawMoney(double money){
    this->money -= money;
    return money;
}

double OverdraftAccount::decreaseMoney(){
    if (money < 0){
        money += money*penalty;
    }
    return money;
}
