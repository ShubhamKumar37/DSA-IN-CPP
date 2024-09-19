#include<IOSTREAM>

using namespace std;

void printCounting(int n)
{
    if(n == 0) return ;

    cout << n << " ";
    printCounting(n - 1);    
    
}

int main()
{
    int n;
    cout << "Enter the value of n = ";
    cin >> n;

    printCounting(n);


    return 0;
}