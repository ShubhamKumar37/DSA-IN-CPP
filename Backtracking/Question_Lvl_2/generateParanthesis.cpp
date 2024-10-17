#include<IOSTREAM>
#include<VECTOR>
#include<STRING>

using namespace std;

void getAllParan(vector<string> &ans, string &temp, int &n, int open, int close)
{
    if(open == n && close == n)
    {
        ans.push_back(temp);
        return ;
    }

    if(open < n)
    {
        temp.push_back('(');
        getAllParan(ans, temp, n, open + 1, close);
        temp.pop_back();
    }
    if(close < open)
    {
        temp.push_back(')');
        getAllParan(ans, temp, n, open, close + 1);
        temp.pop_back();
    }
}

int main()
{
    vector<string> ans;
    string temp = "";
    int n = 4;

    getAllParan(ans, temp, n, 0, 0);

    for(auto i : ans)
    {
        cout << i << endl;
    }


    return 0;
}