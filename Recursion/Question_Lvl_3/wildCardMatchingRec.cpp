#include<IOSTREAM>
#include<STRING>

using namespace std;

bool isMatch(string &str, string &p, int i , int j)
{
    // Base case
    if(i == str.size() && j == p.size()) return true;

    if(i < str.size() && j == p.size()) return false;

    if(i == str.size() && j < p.size())
    {
        while(p[j] == '*') j++;

        if(j != p.size()) return false;

        return true;
    }

    // Processing
    if(str[i] == p[j] || p[j] == '?')
    {
        return isMatch(str, p, i + 1, j + 1);
    }

    if(p[j] == '*')
    {
        bool include = isMatch(str, p, i + 1, j);
        bool exclude = isMatch(str, p, i, j + 1);

        return include || exclude;
    }

    return false;
}

int main()
{
    string str = "abcdef";
    string p = "?b*ef***";

    if(isMatch(str, p, 0, 0))
    {
        cout << "Pattern is matching" << endl;
    }
    else
    {
        cout << "Pattern is not matching" << endl;
    }


    return 0;
}