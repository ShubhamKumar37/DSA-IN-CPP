#include<iostream>
#include<stack>
#include<string> 

using namespace std;

int minAddition(string &str)
{
    stack<char> s;
    int ans = 0;

    for(auto i : str)
    {
        if(i == '(') s.push(i);
        else{
            if(s.empty()) ans++;
            else s.pop();
        }
    }

    return ans + s.size();
}

int main()
{ 
    string str = "))())(((()(((";

    cout << "Number of minimum addition of brackets will be = " << minAddition(str) << endl;


    return 0;
}