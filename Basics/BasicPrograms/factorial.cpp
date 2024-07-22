#include <IOSTREAM>
#define MOD 1000000007

using namespace std;

int factorial(int num)
{
    int value = 1;

    for (int i = 1; i <= num; i++)
    {
        value = (value * i) % MOD;
    }
    
    return value;
}

int main()
{
    int num = 0;
    cout << "Enter the number = ";
    cin >> num;

    cout << factorial(num) << endl;

    return 0;
}