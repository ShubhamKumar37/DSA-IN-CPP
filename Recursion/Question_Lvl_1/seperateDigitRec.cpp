#include<IOSTREAM>

using namespace std;

void seperateDigit(int n)
{
    if(n == 0) return ;

    seperateDigit(n / 10);
    cout << n % 10 << " ";

}

int main()
{
    int n;
    cout << "Enter the value of n = ";
    cin >> n;

    seperateDigit(n);


    return 0;
}