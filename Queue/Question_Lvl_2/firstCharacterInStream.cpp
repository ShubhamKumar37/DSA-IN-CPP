#include <iostream>
#include <string>
#include <queue>

using namespace std;


string getStr(string &str)
{
    string ans = "";
    queue<char> q;
    int arr[26] = {0};

    for(auto i : str)
    {
        arr[(i - 'a')]++;
        q.push(i);
        
        while(!q.empty() && arr[(q.front() - 'a')] > 1) q.pop();
        ans = ans + (q.empty() ? '#' : q.front());
    }

    return ans;
}

int main()
{
    string str = "ccccc";
    cout << getStr(str) << endl;

    return 0;
}