#include <IOSTREAM>
#include <STRING>

using namespace std;

string reversedString1(string str)
{
    string ans;
    int i = 0, j = str.size() - 1;

    while (i < str.size())
    {
        if (!(str[i] >= 'a' && str[i] <= 'z') && !(str[i] >= 'A' && str[i] <= 'Z'))
        {
            ans.push_back(str[i++]);
        }
        else
        {
            if (!(str[j] >= 'a' && str[j] <= 'z') && !(str[j] >= 'A' && str[j] <= 'Z'))
                j--;
            else
            {
                ans.push_back(str[j--]);
                i++;
            }
        }
    }

    return ans;
}

string reversedString2(string s)
{
    int n = s.size();
    int i = 0, j = n - 1;

    while (i < j)
    {
        if(!isalpha(s[i])) i++;
        else if (!isalpha(s[j])) j--;
        else swap(s[i++], s[j--]);
    }

    return s;
}

int main()
{
    string str;
    cout << "Enter the string = ";
    cin >> str;

    // cout << "After reversing the string = " << reversedString1(str) << endl;
    cout << "After reversing the string = " << reversedString2(str) << endl;

    return 0;
}