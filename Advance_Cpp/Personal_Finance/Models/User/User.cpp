#include "User.h"

User :: User(string name)
{
    this -> name = name;
}

void User :: newTransaction(double cost, vector<string> tags = {})
{
    Transaction newT = Transaction(cost, this, tags);
    transactions.push_back(newT);
}