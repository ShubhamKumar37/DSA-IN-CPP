#include<iostream>
#include<string>
#include<stack>
#include<algorithm>

using namespace std;

string getSmallDigit(string &str, int k)
{
    stack<char> s;
    string ans = "";

    for(auto i : str)
    {
        while(!s.empty() && k > 0 && s.top() > i) 
        {
            s.pop();
            k--;
        }
        s.push(i);
    }

    while(k > 0)
    {
        if(!s.empty()) s.pop();
        k--;
    }

    while(!s.empty())
    {
        ans += s.top();
        s.pop();
    }

    while(!ans.empty() && ans.back() == '0') ans.pop_back();

    reverse(ans.begin(), ans.end());

    return ans.empty() ? "0" : ans;
}

int main()
{
    string str = "23123";
    int k = 2;

    cout << "Number after removal of k digits = " << getSmallDigit(str, k) << endl;


    return 0;
}