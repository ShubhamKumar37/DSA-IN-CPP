#include<IOSTREAM>
#include<MATH.H>

using namespace std;

int decimalToBinaryMethod1(int n)
{
    int binaryNumber = 0;
    int i = 0;
    while(n > 0)
    {
        int bit = n % 2;
        n = n / 2;
        binaryNumber = binaryNumber + bit * pow(10, i++);
    }

    return binaryNumber;
}

int decimalToBinaryMethod2(int n)
{
    int binaryNumber = 0;
    int i = 0;

    while(n > 0)
    {
        int bit = n & 1;
        n = n >> 1;

        binaryNumber += bit * pow(10, i++);
    }

    return binaryNumber;
}

int main()
{
    int Number;
    cout << "Enter a number: ";
    cin >> Number;

    int binary1 = decimalToBinaryMethod1(Number);
    cout << "Binary of number " << Number << " is " << binary1 << endl;
    int binary2 = decimalToBinaryMethod2(Number);
    cout << "Binary of number " << Number << " is " << binary2 << endl;

    return 0;
}