#include "bank.h"

Bank::Bank():
    accounts()
{
}

void Bank::addAccount(Account* account){
    accounts.push_back(account);
}


Account* Bank::getByLoginPassword(std::string* login, std::string* password ){
    for(Account* acc : accounts){
        if (0 == acc->getLogin()->compare(*login)){
            if (acc->checkPassword(password)){
                return acc;
            }
        }
    }
    return NULL;
}

void Bank::increaseBalanceForAll(){
    for(Account* acc: accounts){
        acc->increaseMoney();
    }
}
