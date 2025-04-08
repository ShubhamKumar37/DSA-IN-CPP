#include<iostream>
#include<stack>
#include<string>

using namespace std;

bool isValid1(string &str)
{
    stack<char> s;

    for(auto i : str)
    {
        if(s.size() < 2) s.push(i);
        else{
            string temp = "00";
            temp[1] = s.top(); s.pop();
            temp[0] = s.top(); s.pop();
            if(temp + i !=  "abc")
            {
                for(auto j : temp) s.push(j);
                s.push(i);
            }
        }
    }

    return s.empty();
}

bool isValid2(string str)
{
    if(str.size() == 0) return true;

    auto fn = str.find("abc");
    if(fn != string::npos)
    {
        string left = str.substr(0, fn);
        string right = str.substr(fn + 3, str.size());
        return isValid2(left + right);
    }

    return false;
}

int main()
{
    string str = "abcc";

    if(isValid1(str)) cout << "String is valid" << endl;
    if(isValid2(str)) cout << "String is valid" << endl;
    else cout << "String is not valid" << endl;


    return 0;
}