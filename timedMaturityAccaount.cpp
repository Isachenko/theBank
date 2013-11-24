#include "account.h"

TimedMaturityAccount::TimedMaturityAccount(std::string login, std::string password, double money, double percent, double penalty, int term):
    SaveAccount(login, password,money, percent){
    this->penalty = penalty;
    this->term = term;
}


double TimedMaturityAccount::withdrawMoney(double money){
    if (this->money < money) return 0;
    unsigned int t = time(0);
    this->money -= money;
    if (t > term){
        return money;
    }else{
        return (money - (money*penalty));
    }
}
