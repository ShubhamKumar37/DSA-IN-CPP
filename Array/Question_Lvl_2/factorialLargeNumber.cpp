#include <IOSTREAM>
#include <VECTOR>
#include <algorithm>

using namespace std;

void findFactorial(int number)
{
    vector<int> ans = {1};

    for (int i = 2; i <= number; i++)
    {
        int carry = 0;
        int j = 0;
        int length = ans.size();

        while (j < length)
        {
            int mulTemp = ans[j] * i + carry;
            ans[j++] = mulTemp % 10;
            carry = mulTemp / 10;
        }

        while (carry > 0)
        {
            ans.push_back(carry % 10);
            carry /= 10;
        }
    }

    reverse(ans.begin(), ans.end());

    cout << "Factorial for the number is " << endl;

    for (auto i : ans)
    {
        cout << i;
    }
    cout << endl;
}

int main()
{
    int number;

    cout << "Enter the number = ";
    cin >> number;

    findFactorial(number);

    return 0;
}