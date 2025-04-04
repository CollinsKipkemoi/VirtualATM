#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>

using namespace std;

unordered_map<string, tuple<string, double, string>> loadUsers(const string &filename)
{
    unordered_map<string, tuple<string, double, string>> users;
    ifstream file(filename);
    if (!file.is_open())
    {
        throw runtime_error("Could not open file: " + filename);
    }
    string account, pin, transactions;
    double balance;
    while (file >> account >> pin >> balance >> transactions)
    {
        users[account] = make_tuple(pin, balance, transactions);
    }
    file.close();
    return users;
}

bool authenticate(const unordered_map<string, tuple<string, double, string>> &users, const string &account, const string &pin)
{
    auto it = users.find(account);
    return it != users.end() && get<0>(it->second) == pin;
}
