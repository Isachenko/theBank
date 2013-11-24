//#include <iostream>
#include "account.h"
#include "bank.h"

using namespace std;

void balanceAccess(Bank& bank){
    char login[20];
    char password[20];
    printf("Enter Login: ");
    scanf("%s", login);
    printf("Enter Password: ");
    scanf("%s", password);

    std::string strLogin(login);
    std::string strPassword(password);

    Account* accaunt = bank.getByLoginPassword(&strLogin, &strPassword);
    if (accaunt != NULL){
        printf("success access\n");
        while (true){
            printf("0 - cancel\n");
            printf("1 - show balance\n");
            printf("2 - put $100\n");
            printf("3 - withdraw $100\n");
            printf("operation: ");
            short int opNum;
            scanf("%d", &opNum);
            switch (opNum) {
            case 0:
                return;
            case 1:
            {
                double bal = accaunt->getBalance();
                printf("your balance: %lf\n", bal);
                break;
            }
            case 2:
            {
                double money = accaunt->putMoney(100);
                printf("your put: %lf dollars\n", money);
                break;
            }
            case 3:
            {
                double money = accaunt->withdrawMoney(100);
                printf("your get: %lf dollars\n", money);
                break;
            }
            default:
                printf("wrong operation\n");
            }

        }

    }else{
        printf("access denied\n");
    }


}



int main()
{
    Account* acc1 = new Account(std::string("Petrov"), std::string("123"), 100);
    Account* acc2 = new Account(std::string("Ivanov"), std::string("abc"), 50);
    Account* acc3 = new Account(std::string("Isachenko"), std::string("q"), 40);

    Bank bank;
    bank.addAccount(acc1);
    bank.addAccount(acc2);
    bank.addAccount(acc3);

    while (true){
        printf("0 - exit\n");
        printf("1 - get access to account\n");
        printf("Operation: ");
        short int opNum;
        scanf("%d", &opNum);
        switch(opNum){
        case 0:
            return 0;
            break;
        case 1:
            balanceAccess(bank);
            break;
        default:
            printf("wrong operation");
        }
    }
}

