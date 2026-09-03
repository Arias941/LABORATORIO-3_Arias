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

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    bool withdraw(double amount) {
        if (amount > 0 && balance >= amount) {
            balance -= amount;
            return true;
        }
        return false;
    }

    double getBalance() const {
        return balance;
    }

    string getOwner() const {
        return owner;
    }

    bool operator==(const Account& other) const {
        return balance == other.balance;
    }

    static int getTotalAccounts() {
        return totalAccounts;
    }

    void transfer(Account& other, double amount) {
        if (withdraw(amount)) {
            other.deposit(amount);
        }
    }
};

int Account::totalAccounts = 0;

int main() {
    Account acc1("Alice", 1000.0);
    Account acc2("Bob", 500.0);
    Account acc3("Charlie", 1000.0);

    acc1.deposit(200.0);

    bool withdrawResult = acc2.withdraw(1000.0);
    if (!withdrawResult) {
        cout << "Retiro invalido desde la cuenta de " << acc2.getOwner() << endl;
    }

    if (acc1 == acc3) {
        cout << "acc1 y acc3 tienen el mismo saldo" << endl;
    }
    else {
        cout << "acc1 y acc3 tienen saldos diferentes" << endl;
    }

    acc1.transfer(acc2, 200.0);

    cout << "Total de cuentas creadas: " << Account::getTotalAccounts() << endl;

    return 0;
}