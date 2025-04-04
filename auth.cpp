#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <tuple>

using namespace std;

unordered_map<string, tuple<string, double, string>> loadUsers(const string &filename)
{
    unordered_map<string, tuple<string, double, string>> users;
    ifstream file(filename);
    string account, pin, transactions;
    double balance;

    while (file >> account >> pin >> balance)
    {
        getline(file, transactions);
        if (!transactions.empty() && transactions[0] == ' ')
            transactions = transactions.substr(1);
        users[account] = make_tuple(pin, balance, transactions);
    }

    return users;
}

bool authenticate(const unordered_map<string, tuple<string, double, string>> &users, const string &account, const string &pin)
{
    auto it = users.find(account);
    return it != users.end() && get<0>(it->second) == pin;
}
