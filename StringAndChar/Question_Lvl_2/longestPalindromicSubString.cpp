#include<IOSTREAM>
#include<VECTOR>
#include<STRING>

using namespace std;

pair<int, int> findPalindrome(string &str, int i, int j)
{
    int start = -1, end = -1;

    while(i >= 0 && i < str.size())
    {
        if(str[i] != str[j]) break;

        start = i, end = j;
        i--, j++;
    }

    return {start, end};
}


string longestPalindromicString(string &str)
{
    string ans = "";
    int start = 0, end = 0;

    for(int i = 0; i < str.size(); i++)
    {

        // Odd
        int left = i;
        int right = i;
        pair<int, int> index = findPalindrome(str, left, right);

        if((end - start) < (index.second - index.first))
        {
            start = index.first;
            end = index.second;
        }

        // Even
        left = i;
        right = i + 1;
        index = findPalindrome(str, left, right);

        if((end - start) < (index.second - index.first))
        {
            start = index.first;
            end = index.second;
        }
    }

    for(int i = start; i <= end; i++)
    {
        ans.push_back(str[i]);
    }

    return ans;
}

int main()
{
    string str;
    cout << "Enter the string = ";
    cin >> str;

    cout << "This is longest palindromic substring = " << longestPalindromicString(str) << endl;


    return 0;
}