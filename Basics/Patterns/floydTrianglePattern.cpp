#include<IOSTREAM>

using namespace std;

void floydTriangle(int num)
{
    int k = 1;
    for(int i = 0; i < num; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            cout << k++ << " ";
        }
        cout << endl;
    }
}

int main()
{
    int num = 0;
    cout << "Enter the number = ";
    cin >> num;

    floydTriangle(num);

    return 0;
}