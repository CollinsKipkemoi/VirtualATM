#include <iostream>
#include <unordered_map>
#include <string>
#include <fstream>
#include "auth.cpp"
#include "account-manager.cpp"

using namespace std;

void saveUsers(const string &filename, const unordered_map<string, tuple<string, double, string>> &users)
{
    ofstream file(filename);
    for (const auto &user : users)
    {
        file << user.first << " " << get<0>(user.second) << " " << get<1>(user.second) << " " << get<2>(user.second) << "\n";
    }
}

int main()
{
    const string filename = "users.txt";
    auto users = loadUsers(filename);

    string account, pin;
    cout << "Enter account number: ";
    cin >> account;
    cout << "Enter PIN: ";
    cin >> pin;

    if (users.find(account) != users.end() && get<0>(users[account]) == pin)
    {
        cout << "Authentication successful!\n";
        double balance = getBalance(users, account);
        cout << "Account: " << account << " Balance: " << balance << endl;

        // Operations
        int choice;
        double amount;
        do {
            cout << "\n********** ATM **********\n";
            cout << "1. Check Balance\n";
            cout << "2. Deposit\n";
            cout << "3. Withdraw\n";
            cout << "4. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            try {
                switch (choice) {
                    case 1:
                        cout << "Current balance: " << balance << endl;
                        break;
                    case 2:
                        cout << "Enter amount to deposit: ";
                        cin >> amount;
                        if (amount <= 0) {
                            cout << "Invalid amount. Please enter a positive number." << endl;
                            break;
                        }
                        balance = deposit(users, account, amount);
                        cout << "Deposit successful. New balance: " << balance << endl;
                        saveUsers(filename, users);  // Save changes to file
                        break;
                    case 3:
                        cout << "Enter amount to withdraw: ";
                        cin >> amount;
                        if (amount <= 0) {
                            cout << "Invalid amount. Please enter a positive number." << endl;
                            break;
                        }
                        balance = withdraw(users, account, amount);
                        cout << "Withdrawal successful. New balance: " << balance << endl;
                        saveUsers(filename, users);  // Save changes to file
                        break;
                    case 4:
                        cout << "Thank you for using our ATM. Goodbye!" << endl;
                        break;
                    default:
                        cout << "Invalid choice. Please try again." << endl;
                        break;
                }
            } catch (const runtime_error& e) {
                cout << "Error: " << e.what() << endl;
            }
        } while (choice != 4);
    }
    else
    {
        cout << "Invalid account number or PIN.\n";
    }

    return 0;
}
