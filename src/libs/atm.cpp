#include "atm.h"

using namespace std;

ATM::ATM(){
    Account* acc1 = new SaveAccount(std::string("Petrov"), std::string("123"), 100, 0.05);
    Account* acc2 = new CheckingAccount(std::string("Ivanov"), std::string("abc"), 50, 2, 10);
    Account* acc3 = new Account(std::string("Isachenko"), std::string("q"), 40);

    bank.addAccount(acc1);
    bank.addAccount(acc2);
    bank.addAccount(acc3);
}



void ATM::balanceAccess(){
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
            printf("2 - put $10\n");
            printf("3 - withdraw $10\n");
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
                double money = accaunt->putMoney(10);
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


void ATM::start()
{

    while (true){
        printf("0 - exit\n");
        printf("1 - get access to account\n");
        printf("Operation: ");
        short int opNum;
        scanf("%d", &opNum);
        switch(opNum){
        case 0:
            return;
            break;
        case 1:
            balanceAccess();
            break;
        default:
            printf("wrong operation");
        }
    }
}

