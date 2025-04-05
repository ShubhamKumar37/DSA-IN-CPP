#include <iostream>
#include <stack>
#include <string>

using namespace std;

int solve(string &s)
{
    stack<int> S;
    int ans = 0;
    int num = 0;
    int sign = 1;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            int temp = s[i] - '0';
            num = num * 10 + temp;
        }
        else if (s[i] == '+' || s[i] == '-')
        {
            ans += (num * sign);
            num = 0;
            sign = s[i] == '+' ? 1 : -1;
        }
        else if (s[i] == '(')
        {
            ans += (num * sign);
            S.push(ans);
            S.push(sign);
            ans = num = 0;
            sign = 1;
        }
        else if (s[i] == ')')
        {
            ans += (num * sign);
            ans *= S.top();
            S.pop();
            ans += S.top();
            S.pop();
            num = 0;
            sign = 1;
        }
    }
    return ans + (num * sign);

}

int main()
{
    string str = "(1+(4123+521+2)-3)+(6213+8)";

    cout << "This is the answer of expression = " << solve(str) << endl;

    return 0;
}