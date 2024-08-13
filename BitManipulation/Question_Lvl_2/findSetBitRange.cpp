#include <IOSTREAM>
#include <MATH.H>

using namespace std;

int findSetBit(int n)
{
    int sum = 0;
    int i = 1;

    while (true)
    {
        int restSetBitSum = 0;
        int upperCompleteSetBitSum = 0;
        int mul = pow(2, i - 1);

        upperCompleteSetBitSum = (n >> i) * mul;
        restSetBitSum = (n % (int)(pow(2, i)) - mul) + 1;

        if (upperCompleteSetBitSum <= 0 && restSetBitSum <= 0)
        {
            break;
        }

        sum += upperCompleteSetBitSum;
        if (restSetBitSum > 0)
        {
            sum += restSetBitSum;
        }

        i++;
    }

    return sum;
}

int main()
{
    int n = 0;

    cout << "Enter the value = ";
    cin >> n;

    cout << "Number of set bit between 1 to " << n << " is " << findSetBit(n) << endl;

    return 0;
}