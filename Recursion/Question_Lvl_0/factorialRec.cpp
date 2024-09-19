#include<IOSTREAM>

using namespace std;

int factorialRec(int n)
{
    if(n == 0) return 1;

    return n * factorialRec(n - 1);
}

int main()
{
    int n;

    cout << "Enter the number = ";
    cin >> n;

    cout << "Factorial of the number = " << factorialRec(n) << endl;


    return 0;
}