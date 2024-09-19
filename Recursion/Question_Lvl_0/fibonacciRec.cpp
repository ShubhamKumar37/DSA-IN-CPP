#include<IOSTREAM>

using namespace std;


int fibonacci(int n)
{
    if(n == 0 || n == 1)
    {
        return n;

    }

    int val1 = fibonacci(n - 1);
    int val2 = fibonacci(n - 2);

    return val1 + val2;
}

int main()
{
    int n;

    cout << "Enter the number = ";
    cin >> n;

    cout << fibonacci(n) << endl;


    return 0;
}