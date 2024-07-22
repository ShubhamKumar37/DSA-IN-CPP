#include<IOSTREAM>

using namespace std;

int main()
{
    int num = 0;
    cout << "Enter the number = ";
    cin >> num;

    cout << "Number is " << (num & 1 ? "Odd" : "Even") << endl;

    return 0;
}