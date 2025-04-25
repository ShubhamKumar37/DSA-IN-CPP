#include<stack>
#include<iostream>
#include<string>

using namespace std;

string simplifiedPath(string &str)
{
    stack<string> s;
    string temp = "";

    for(auto i : str)
    {
        if(i == '/')
        {
            if(temp == "") continue;
            else if(!s.empty() && temp == "..") s.pop();
            else if(!s.empty() && temp == ".") temp = "";
            else s.push(temp);
            temp = "";
        }
        else temp += i;
    }

    if(temp == "..")
    {
        if(!s.empty()) s.pop();
        temp = "";
    }
    if(temp != "" && temp != ".") s.push(temp);
    temp = "";


    while(!s.empty())
    {
        cout << s.top() << " ";
        temp = '/' + s.top() + temp;
        s.pop();
    }
    cout << endl;

    return temp == "" ? "/" : temp;
}

int main()
{
    // string str = "/.../a/../b/c/../d/./";
    string str = "/home//foo/";

    cout << simplifiedPath(str) << endl;

    return 0;
}