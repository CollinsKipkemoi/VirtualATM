#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>

using namespace std;

unordered_map<string, string> loadUsers(const string &filename)
{
    unordered_map<string, string> users;
    ifstream file(filename);
    string account, pin;

    while (file >> account >> pin)
    {
        users[account] = pin;
    }

    return users;
}

bool authenticate(const unordered_map<string, string> &users, const string &account, const string &pin)
{
    auto it = users.find(account);
    return it != users.end() && it->second == pin;
}
