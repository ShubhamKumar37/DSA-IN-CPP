#include<IOSTREAM>

using namespace std;

int GCD(int a, int b)
{
    if(a == 0) return b;
    if(b == 0) return a;

    while(a > 0 && b > 0)
    {
        // Can use "-" instead of "%"
        if(a > b) a = a % b; 
        else b = b % a;
    }

    return a == 0 ? b : a;
}

int main()
{
    int num1, num2; 

    cin >> num1 >> num2;

    cout << "This will be the GCD of 2 number = " << GCD(num1, num2) << endl;


    return 0;
}