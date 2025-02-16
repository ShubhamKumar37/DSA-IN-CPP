#include<IOSTREAM>
#include<STRING>

using namespace std;

bool isPalindrome(string str, int s, int e)
{
    while(s <= e)
    {
        if(str[s] != str[e]) return false;

        s++, e--;
    }

    return true;
}

int findPossiblePalindromeWindow(string str, int window)
{
    int i = 0, j = window - 1, count = 0;

    while(j < str.size())
    {
        if(isPalindrome(str, i, j)) count++;

        i++, j++;
    }

    return count;
}


int findSubStrPalindrom(string str)
{

    int count = str.size();

    for(int i = 2; i <= str.size(); i++)
    {
        count += findPossiblePalindromeWindow(str, i);
    }

    return count;
}

int main()
{
    string str;
    cin >> str;

   cout << "Number of substring as palindrome are " << findSubStrPalindrom(str) << endl;


    return 0;
}