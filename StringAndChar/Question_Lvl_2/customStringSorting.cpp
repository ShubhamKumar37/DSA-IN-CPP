#include<IOSTREAM>
#include<STRING>
#include<algorithm>

using namespace std;


string orderString1(string order, string str)
{
    char arr[26] = {0};
    string ans;

    for(int i = 0; i < str.size(); i++) arr[str[i] - 'a']++;

    for(auto i : order)
    {
        int index = i - 'a';
        for(int j = 0; j < arr[index]; j++) ans.push_back((char)(index + 'a'));
        arr[index] = 0;
    }

    for(int i = 0; i < 26; i++)
    {
        for(int j = 0; j < arr[i]; j++) ans.push_back((char)(i + 'a'));
    }

    return ans;
}

string s;
static bool cmp(char& a, char& b)
{
    return s.find(a) < s.find(b);
}

string orderString2(string order, string str)
{
    s = order;
    sort(str.begin(), str.end(), cmp);

    return str;
}

int main()
{
    string order;
    string str;

    cin >> order;
    cin >> str;

    // cout << "After following the order the string = " << orderString1(order, str) << endl;
    cout << "After following the order the string = " << orderString2(order, str) << endl;


    return 0;
}