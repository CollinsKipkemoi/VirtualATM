#include <iostream>
#include <unordered_map>
#include <string>
#include "auth.cpp" 

using namespace std;

int main()
{
    const string filename = "users.txt";
    auto users = loadUsers(filename);

    string account, pin;
    cout << "Enter account number: ";
    cin >> account;
    cout << "Enter PIN: ";
    cin >> pin;

    if (authenticate(users, account, pin))
    {
        cout << "Authentication successful!\n";
    }
    else
    {
        cout << "Invalid account number or PIN.\n";
    }

    return 0;
}
