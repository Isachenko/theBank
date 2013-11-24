#include "account.h"

Account::Account(std::string login, std::string password, double money)
{
    this->login = login;
    this->password = password;
    this->money = money;
}

double Account::putMoney(double money){
    this->money += money;
    return money;
}

double Account::withdrawMoney(double money){
    if (this->money < money){
        return 0;
    }
    this->money -= money;
    return money;
}

double Account::getBalance(){
    return money;
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

