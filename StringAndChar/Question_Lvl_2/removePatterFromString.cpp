#include<IOSTREAM>
#include<STRING>

using namespace std;

string removePattern2(string str, string pattern)
{
    int i = 0;
    int n = pattern.size();

    while(i < str.size())
    {
        string subString = str.substr(i, n);

        if(subString == pattern)
        {
            str.erase(i, n);
            i = (i - n + 1);
            if(i < 0) i = 0;
        }
        else i++;
    }

    return str;
}

string removePattern1(string str, string pattern)
{
    auto it = str.find(pattern);

    while(it != string::npos)
    {
        str.erase(it, pattern.size());
        it = str.find(pattern);
    }

    return str;
}

int main()
{
    string str;
    string pattern;
    cin >> str >> pattern;

    // cout << "Final string after removing all the occurance is " << removePattern1(str, pattern) << endl;
    cout << "Final string after removing all the occurance is " << removePattern2(str, pattern) << endl;



    return 0;
}