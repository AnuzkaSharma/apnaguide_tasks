#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>


using namespace std;

class Account {
private:
    int accountNumber;
    double balance;
public:
    Account(int accountNumber, double balance) : accountNumber(accountNumber), balance(balance) {}

    int getAccountNumber() const {
        return accountNumber;
    }


    void deposit(double amount) {
        balance += amount;
    }

    bool withdraw(double amount) {
        if (amount > balance) {
            return false;
        } else {
            balance -= amount;
            return true;
        }
    }

    void displayAccountDetails() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << fixed << setprecision(2) << balance << endl;
    }
};

class BankingSystem {
private:
    vector<Account> accounts;

public:
    void createAccount(int accountNumber, double initialBalance) {
        accounts.push_back(Account(accountNumber, initialBalance));
    }

    void deposit(int accountNumber, double amount) {
        for (auto &account : accounts) {
            if (account.getAccountNumber() == accountNumber) {
                account.deposit(amount);
                cout << "Deposit successful." << endl;
                return;
            }
        }
        cout << "Account not found." << endl;
    }

    bool withdraw(int accountNumber, double amount) {
        for (auto &account : accounts) {
            if (account.getAccountNumber() == accountNumber) {
                if (account.withdraw(amount)) {
                    cout << "Withdrawal successful." << endl;
                    return true;
                } else {
                    cout << "Insufficient balance." << endl;
                    return false;
                }
            }
        }
        cout << "Account not found." << endl;
        return false;
    }

    void displayAccountDetails(int accountNumber) const {
        for (const auto &account : accounts) {
            if (account.getAccountNumber() == accountNumber) {
                account.displayAccountDetails();
                return;
            }
        }
        cout << "Account not found." << endl;
    }

    void displayAllAccounts() const {
        if (accounts.empty()) {
            cout << "No accounts in the system." << endl;
            return;
        }
        for (const auto &account : accounts) {
            account.displayAccountDetails();
            cout << "--------------------" << endl;
        }
    }

    int getAccountIndex(int accountNumber) const {
        for (size_t i = 0; i < accounts.size(); i++) {
            if (accounts[i].getAccountNumber() == accountNumber) {
                return i;
            }
        }
        return -1;
    }

};

int main() {
    BankingSystem bank;
    int choice;

    do {
        cout << "\nBanking System Menu:" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Display Account Details" << endl;
        cout << "5. Display All Accounts" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int accountNumber;
                double initialBalance;
                cout << "Enter account number: ";
                cin >> accountNumber;
                cout << "Enter initial balance: ";
                cin >> initialBalance;
                bank.createAccount(accountNumber, initialBalance);
                cout << "Account created successfully." << endl;
                break;
            }
            case 2: {
                int accountNumber;
                double amount;
                cout << "Enter account number: ";
                cin >> accountNumber;
                cout << "Enter deposit amount: ";
                cin >> amount;
                bank.deposit(accountNumber, amount);
                break;
            }
            case 3: {
                int accountNumber;
                double amount;
                cout << "Enter account number: ";
                cin >> accountNumber;
                cout << "Enter withdrawal amount: ";
                cin >> amount;
                bank.withdraw(accountNumber, amount);
                break;
            }
            case 4: {
                int accountNumber;
                cout << "Enter account number: ";
                cin >> accountNumber;
                bank.displayAccountDetails(accountNumber);
                break;
            }
            case 5:
                bank.displayAllAccounts();
                break;
            case 6:
                cout << "Exiting the banking system." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}