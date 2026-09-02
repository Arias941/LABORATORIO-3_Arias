#include <iostream>
#include <string>

using namespace std;

class Account {
private:
    string owner;
    double balance;
    static int totalAccounts;

public:
    Account(string owner, double initialBalance) {
        this->owner = owner;
        if (initialBalance >= 0) {
            this->balance = initialBalance;
        }
        else {
            this->balance = 0;
        }
        totalAccounts++;
    }

    Account(const Account& other) {
        this->owner = other.owner;
        this->balance = other.balance;
        totalAccounts++;
    }