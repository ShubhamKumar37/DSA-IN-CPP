#include<IOSTREAM>
#include<STRING>

using namespace std; 

bool checkPalindrome(string &str, int index)
{
    if(index >= (str.size() >> 1)) return true;
    if(str[index] != str[str.size() - 1 - index]) return false;

    return checkPalindrome(str, index + 1);
}

int main()
{
    // string str = "shubham";
    string str = "racecar";

    if(checkPalindrome(str, 0)) cout << "Palindrome" << endl;
    else cout << "Not a palindrome" << endl;


    return 0;
}