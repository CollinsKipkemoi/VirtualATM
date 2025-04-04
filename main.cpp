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
        cout << "Account: " << account << " Balance: " << balance;

    }
    else
    {
        cout << "Invalid account number or PIN.\n";
    }

    return 0;
}
