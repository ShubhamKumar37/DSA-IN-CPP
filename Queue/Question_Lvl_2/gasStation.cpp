#include <iostream>
#include <vector>

using namespace std;

int findStart(vector<int> &gas, vector<int> &cost)
{
    int start = 0;
    int bal = 0;
    int def = 0;

    for(int i = 0; i < gas.size(); i++)
    {
        bal += (gas[i] - cost[i]);
        if(bal < 0)
        {
            def += abs(bal);
            bal = 0;
            start = i + 1;
        }
    }

    if(bal - def < 0) return -1;
    return start;
}

int main()
{   
    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};

    cout << "The starting point will be = " << findStart(gas, cost) << endl;


    return 0;
}