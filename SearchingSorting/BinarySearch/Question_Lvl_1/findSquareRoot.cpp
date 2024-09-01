#include <iostream>

using namespace std;

int findSquareRoot(int num)
{
    if (num == 0)
    {
        return 0;
    }

    int s = 1, e = num;
    long long int mid = s + ((e - s) >> 1);
    int ans = 0;

    while (s <= e)
    {
        long long int square = mid * mid;

        if (square == num)
        {
            ans = mid;
            break;
        }
        else if (square < num)
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

    return ans;
}

int main()
{
    int num;
    cout << "Enter the value of num = ";
    cin >> num;

    cout << "Square root of num (approx.) is " << findSquareRoot(num) << endl;

    return 0;
}