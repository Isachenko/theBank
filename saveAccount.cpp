#include "account.h"

SaveAccount::SaveAccount(std::string login, std::string password, double money, double percent):
    Account(login, password, money){
    this->percent = percent;
}

void SaveAccount::increaseMoney(){
    money += money*percent;
}
