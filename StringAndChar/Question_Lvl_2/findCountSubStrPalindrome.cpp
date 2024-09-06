#include <iostream>
#include <string>

using namespace std;

int subStrPalindrome(string s, int n, int i, int j)
{
    int ans = 0;

    while (i >= 0 && j < n)
    {
        if (s[i] != s[j])
            break;

        i--, j++, ans++;
    }

    return ans;
}

int countPS(string s, int n)
{
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        // Even
        int left = i;
        int right = i + 1;
        ans += subStrPalindrome(s, n, left, right);

        // Odd
        left = i - 1;
        right = i + 1;
        ans += subStrPalindrome(s, n, left, right);
    }

    return ans;
}

bool isPalindrome(string str, int s, int e)
{
    while (s <= e)
    {
        if (str[s] != str[e])
            return false;

        s++, e--;
    }

    return true;
}

int findPossiblePalindromeWindow(string str, int window)
{
    int i = 0, j = window - 1, count = 0;

    while (j < str.size())
    {
        if (isPalindrome(str, i, j))
            count++;

        i++, j++;
    }

    return count;
}

int findSubStrPalindrom(string str)
{

    int count = str.size();

    for (int i = 2; i <= str.size(); i++)
    {
        count += findPossiblePalindromeWindow(str, i);
    }

    return count;
}

int main()
{
    string s;
    cin >> s;

    // Make sure that every substring must have length greater then equal to 2
    cout << "Number of palindromic string are " << countPS(s, s.size()) << endl;
    cout << "Number of substring as palindrome are " << findSubStrPalindrom(s) << endl;

    return 0;
}