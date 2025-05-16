#include <iostream>
#include <queue>
#include <string>

using namespace std;

string whoWon(string &str)
{
    queue<int> r;
    queue<int> d;

    int i = 0;

    for(; i < str.size(); i++)
    {
        if(str[i] == 'D') d.push(i);
        else r.push(i);
    }

    while(!r.empty() && !d.empty())
    {
        int rInd = r.front(); r.pop();
        int dInd = d.front(); d.pop();

        if(rInd < dInd) r.push(rInd + ++i);
        else d.push(dInd + ++i);
    }

    return r.empty() ? "Dire" : "Radient";
}

int main()
{
    // string str = "RDRDDRDDRDDRDDRDDRDDRDDRDDRDDRDDRDDRDDRDDRDDRDDRDDRDDRDDRDDRDDRDDRDDRDDRDDRDDRDDRDDRDDRDDRDDRDDRDDRDDRDDRDDRDDRDDRDDRDDRDDRDDRDDRDDRDDRDDRDDRDDRDDRDDRDDRDDRDDRDDD";
    string str = "DRR";

    cout << "They won the match = " << whoWon(str) << endl;

    return 0;
}