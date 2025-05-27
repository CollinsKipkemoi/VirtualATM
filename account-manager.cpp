#include <iostream>
#include <unordered_map>
#include <tuple>

using namespace std;

double getBalance(const unordered_map<string, tuple<string, double, string>>& data, string account)
{
    auto userData = data.find(account);
    if (userData != data.end()) {
        double balance = get<1>(userData->second);
        return balance;
    }
    throw runtime_error("Account not found");
}

double deposit(unordered_map<string, tuple<string, double, string>>& data, string account, double amount)
{
    auto userData = data.find(account);
    if (userData != data.end()) {
        double balance = get<1>(userData->second);
        balance += amount;
        get<1>(userData->second) = balance;
        return balance;
    }
    throw runtime_error("Account not found");
}

double withdraw(unordered_map<string, tuple<string, double, string>>& data, string account, double amount)
{
    auto userData = data.find(account);
    if (userData != data.end()) {
        double balance = get<1>(userData->second);
        if (balance >= amount) {
            balance -= amount;
            get<1>(userData->second) = balance;
            return balance;
        }
        throw runtime_error("Insufficient balance");
    }
    throw runtime_error("Account not found");
}
