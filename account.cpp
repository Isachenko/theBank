#include "account.h"

Account::Account(std::string login, std::string password, double money, double percent)
{
    this->login = login;
    this->password = password;
    this->money = money;
    this->percent = percent;
}

void Account::increaseMoney(){
    money += money*percent;
}

void Account::decreaseMoney(){
    money -= money*percent;
}


std::string* Account::getLogin(){
    return &login;
}

bool Account::checkPassword(std::string* password){
    if (0 == this->password.compare(*password)){
        return true;
    }
    return false;
}

double Account::getBalance(){
    return money;
}
