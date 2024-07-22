#include<IOSTREAM>

using namespace std;

int findSetBit(int num)
{
    int sum = 0;
    while(num > 0)
    {
        sum += num & 1;
        num = num >> 1;
    }

    return sum;
}

int main()
{
    int num = 0; 
    cout << "Enter a number = ";
    cin >> num;

    cout << "Number of set bit in " << num << " is " << findSetBit(num) << endl;

    return 0;
}