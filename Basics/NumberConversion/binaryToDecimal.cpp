#include<IOSTREAM>
#include<MATH.H>

using namespace std;

int binaryToDecimal(int n)
{
    int number = 0;
    int i = 0;
    
    while(n > 0)
    {
        int singleNumber = n % 10;
        n = n / 10;

        number += singleNumber * pow(2, i++);
    }

    return number;
}

int main()
{
    int binaryNumber;
    cout << "Enter a binary number: ";
    cin >> binaryNumber;

    int decimalNumber = binaryToDecimal(binaryNumber);
    cout << "Decimal number for " << binaryNumber << " is " << decimalNumber << endl;

    return 0;
}