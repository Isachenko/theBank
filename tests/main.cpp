#include <unittest++/UnitTest++.h>
#include "../src/libs/atm.h"

struct JekaFixture
{
  JekaFixture():acc("Jeka", "peka", 300) {}
  ~JekaFixture() {}

  Account acc;
};

SUITE(accountTests){

    TEST_FIXTURE(JekaFixture, test1) {
        CHECK(acc.getBalance() == 300);
    }

    TEST_FIXTURE(JekaFixture, test2) {
        CHECK(acc.withdrawMoney(20) == 20);
    }

    TEST(test3) {
        CheckingAccount acc("Jeka", "peka", 21, 10, 0);
        CHECK(acc.withdrawMoney(20) == 0);
    }

    TEST(test4) {
        Account* acc;
        acc = new CheckingAccount("Jeka", "peka", 21, 10, 0);
        CHECK(acc->withdrawMoney(20) == 0);
        delete acc;
    }

    TEST(test5) {
        Account acc("Jeka", "peka", 21);
        Bank bank;
        bank.addAccount(&acc);
        std::string login = "Jeka";
        std::string password = "peka";
        CHECK(bank.getByLoginPassword(&login, &password) == &acc);
    }
}

SUITE(bankTests){
    TEST(test5) {
        Account acc("Jeka", "peka", 21);
        Bank bank;
        bank.addAccount(&acc);
        std::string login = "Jeka";
        std::string password = "peka";
        CHECK(bank.getByLoginPassword(&login, &password) == &acc);
    }
    TEST(test6) {
        Account acc("Jeka", "peka", 21);
        Bank bank;
        bank.addAccount(&acc);
        std::string login = "Jeka";
        std::string password = "peka";
        CHECK(bank.getByLoginPassword(&login, &password)->getBalance() == 21);
    }
}

SUITE(atmTests){
    TEST(test7) {
        ATM atm;
        CHECK(&atm != NULL);
    }
}

int main()
{
    int x;
    return UnitTest::RunAllTests();
}
