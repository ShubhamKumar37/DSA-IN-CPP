#include<IOSTREAM>

using namespace std;

void pascalTriangle(int num)
{
    for(int i = 1; i <= num; i++)
    {
        int k = 1;
        for(int j = 1; j <= i; j++)
        {
            cout << k << " ";
            k = (k * (i - j)) / j;
        }
        cout << endl;
    }
}

int main()
{
    int num = 0;
    cout << "Enter the number = ";
    cin >> num;

    pascalTriangle(num);

    return 0;
}