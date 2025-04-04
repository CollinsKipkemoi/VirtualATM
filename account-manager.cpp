#include <iostream>
#include <unordered_map>
#include <tuple>

using namespace std;

double getBalance(unordered_map<string, tuple<string, double, string>> data, string account)
{
    auto userData = data.find(account);
    if (userData != data.end()) {
        double balance = get<1>(userData->second);
        return balance;
    }
    throw runtime_error("Account not found");
}
