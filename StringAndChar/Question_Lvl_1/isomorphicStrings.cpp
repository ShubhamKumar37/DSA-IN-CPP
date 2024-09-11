#include<IOSTREAM>
#include<STRING>

using namespace std;

bool isIsomorphicString(string &s, string &t)
{

    if(s.size() != t.size()) return false;

    int charMap[256] = {0};
    bool isMapped[256] = {false};

    for(int i = 0; i < s.size(); i++)
    {
        if(charMap[s[i]] == 0 && isMapped[t[i]] == false)
        {
            charMap[s[i]] = t[i];
            isMapped[t[i]] = true;
        }
    }

    for(int i = 0; i < s.size(); i++)
    {
        if((char)charMap[s[i]] != t[i]) return false;
    }

    return true;
}

int main()
{
    string s, t;

    cin >> s >> t;

    if(isIsomorphicString(s, t))
    {
        cout << "Both string are isomorphic " << endl;
    }
    else
    {
        cout << "Not an isomorphic " << endl;
    }

    return 0;
}