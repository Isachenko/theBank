#include "account.h"

CheckingAccount::CheckingAccount(std::string login, std::string password, double money, double fee, int quota):
    Account(login, password, money){
    this->fee = fee;
    this->quota = quota;
    this->curWithdrawCount = 0;
}

double CheckingAccount::withdrawMoney(double money){
    ++curWithdrawCount;
    double decreaseValue = 0;
    if (curWithdrawCount > quota){
        decreaseValue = money + fee;
    }else{
        decreaseValue = money;
    }

    if (this->money < decreaseValue){
        return 0;
    }else{
        this->money -= decreaseValue;
    }
    return money;
}
