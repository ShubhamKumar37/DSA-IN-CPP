#include "Transaction.h"

string Transaction :: getTime()
{
    return ctime(&now);
}

Transaction ::  Transaction(double cost, User user, vector<string> tags)
{
    this -> cost = cost;
    this -> user = user;
    this -> tags = tags;
    this -> id = id + 1;
}

string Transaction :: getTransaction()
{
    string ans = "";

    ans = curr.user.name + "  -  " + curr.cost + "  -  " + curr.getTime + "  -  ";
    for(int j = 0; j < tags.size(); j++) 
        ans = ans + curr.tags[j] + (j + 1 == curr.tags.size() ? "" : "  -  ");
    
    ans += '\n';
    return ans;
}

double displayTransactions(vector<Transaction>& allData)
{ 
    double sum = 0;
    cout << "No.   -  Name  -  Cost  -  Time  -  Tags" << endl;
    for(int i = 0; i < allData.size(); i++)
    {
        cout << allData[i];
        sum += allData[i].cost;
    }

    return sum;
}