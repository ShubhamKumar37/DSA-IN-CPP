#include <iostream>
#include <vector>
#include "../Transaction/Transaction.h"

using namespace std;

class User
{
    public: 
    string name;
    vector<Transaction> transactions;

    User(string);

    void newTransaction(double cost, vector<string> tags = {});
};