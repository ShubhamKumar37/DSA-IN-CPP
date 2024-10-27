#include<IOSTREAM>
#include<STRING>
#include<algorithm>

using namespace std;

void getSum1(string &str1, string &str2, int indexI, int indexJ, int carry, string &ans)
{
    if(indexI < 0 && indexJ < 0)
    {
        if(carry > 0)
        {
            ans += (carry + '0');
        }

        return ;
    }

    int num1 = (indexI >= 0 ? str1[indexI] : '0') - '0';
    int num2 = (indexJ >= 0 ? str2[indexJ] : '0') - '0';
    int sum = num1 + num2 + carry;

    carry = sum / 10;
    ans += (sum % 10 + '0');

    getSum1(str1, str2, indexI - 1, indexJ - 1, carry, ans);
}

string getSum2(string &str1, string &str2, int i, int j, int carry)
{
    if(i < 0 && j < 0)
    {
        if(carry > 0)
        {
            return string(1, carry + '0');
        }
        return "";
    }

    int num1 = (i >= 0 ? str1[i] : '0') - '0';
    int num2 = (j >= 0 ? str2[j] : '0') - '0';
    int sum = num1 + num2 + carry;

    carry = sum / 10;
    return string(1, sum % 10 + '0') + getSum2(str1, str2, i - 1, j - 1, carry);
}

int main()
{
    string str1 = "32423";
    string str2 = "6454762534";
    // string ans = "";

    // getSum1(str1, str2, str1.size() - 1, str2.size() - 1, 0, ans);

    string ans = getSum2(str1, str2, str1.size() - 1, str2.size() - 1, 0);

    while(ans.size() > 1 && ans.back() == '0')ans.pop_back();

    reverse(ans.begin(), ans.end());

    cout << "After addition of 2 string this is the result " << endl << ans << endl;

    return 0;
}