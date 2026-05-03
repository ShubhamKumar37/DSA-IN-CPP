#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include "../User/User.h"


class Transaction{
    public:
    double cost;
    User user;
    vector<string> tags;
    time_t now = time(nullptr);
    static int id = 0;

    Transaction(double cost, User user, vector<string> tags);

    string getTime();
    string getTransaction();
};

double displayTransactions(vector<Transaction> &allData);