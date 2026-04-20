#pragma once
#include <iostream>
#include <vector>
#include <ctime>

class Transaction{
    public:
    double cost;
    string userName;
    vector<string> tags;
    time_t now = time(nullptr);
    static int id = 0;

    Transaction(double , string, vector<string>);

    string getTime();
    string getTransaction();
};

double displayTransactions(vector<Transaction> &allData);