#include <IOSTREAM>

using namespace std;

int reverseNumber(int num)
{
    int ans = 0;

    // "<=" because minimum value for 32bit will have +1 if we convert it to positive number but INT_MAX = -(INT_MIN) - 1 after convertion number will overflow
    if (num <= INT_MIN)
    {
        return 0;
    }
    int temp = num < 0 ? num * -1 : num;

    while (temp > 0)
    {
        if (ans > INT_MAX / 10)
        {
            return 0;
        }
        int rem = temp % 10;
        ans = ans * 10 + rem;
        temp = temp / 10;
    }

    return num < 0 ? ans * -1 : ans;
}

int main()
{
    int num = 0;
    cout << "Enter the number = ";
    cin >> num;

    cout << reverseNumber(num) << endl;

    return 0;
}