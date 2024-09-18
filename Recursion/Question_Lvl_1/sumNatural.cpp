#include<IOSTREAM>

using namespace std;

int printSum(int n)
{
    if(n == 1) return n;


    return n + printSum(n - 1);
}

int main()
{
    int n;

    cout << "Enter the value of n = ";
    cin >> n;

    cout << "Sum of n natural number is " << printSum(n) << endl;


    return 0;
}