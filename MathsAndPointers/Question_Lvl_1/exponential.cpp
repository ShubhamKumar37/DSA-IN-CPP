#include<IOSTREAM>

using namespace std;

int exponent1(int num, int exp)
{
    int ans = 1;
    for(int i = 0; i < exp; i++)
    {
        ans *= num;
    }

    return ans;
}

int exponent(int num, int exp)
{
    int ans = 1;

    while(exp >= 0)
    {
        if(exp & 1)
        {
            ans *= num;
        }

        num = num * num;
        exp >>= 1;
    }

    return ans;
}

int main()
{

    int num;
    cout << "Enter the number = ";
    cin >> num;

    cout << "Number of digit in number is " << exponent1(num, 7)  << endl;


    return 0;
}