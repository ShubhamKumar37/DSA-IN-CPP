#include <IOSTREAM>

using namespace std;

long long divide(long long dividend, long long divisor)
{
    // code here
    if (abs(dividend) < abs(divisor))
    {
        return 0;
    }

    long long s = 1;
    long long e = abs(dividend);
    long long mid = s + ((e - s) >> 1);
    long long ans = 1;

    while (s <= e)
    {
        if (mid * abs(divisor) <= abs(dividend))
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }

        mid = s + ((e - s) >> 1);
    }

    if ((dividend >= 0 && divisor < 0) || (dividend < 0 && divisor >= 0))
    {
        return -ans;
    }

    return ans;
}

int main()
{
    int dividend, divisor;

    cin >> dividend >> divisor;

    cout << "Answer of divide is " << divide(dividend, divisor) << endl;

    return 0;
}