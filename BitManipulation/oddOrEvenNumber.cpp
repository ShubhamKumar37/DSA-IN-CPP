#include<IOSTREAM>

using namespace std;

bool findEvenOdd(int num)
{
    return num & 1;
}

int main()
{
    int num = 0;
    cout << "Enter a number = ";
    cin >> num;

    cout << "The number " << num << " is " << (findEvenOdd(num) == false ? "Even" : "Odd") << endl;

    return 0;
}