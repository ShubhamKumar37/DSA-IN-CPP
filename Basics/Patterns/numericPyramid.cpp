#include<IOSTREAM>

using namespace std;

void halfPyramid(int num)
{
    for(int i = 0; i < num; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            cout << j + 1 << " ";
        }
        cout << endl;
    }
}

void invertedHalfPyramid(int num)
{
    for(int i = 0; i < num; i++)
    {
        for(int j = 0; j < num - i; j++)
        {
            cout << j + 1 << " ";
        }
        cout << endl;
    }
}

int main()
{
    int num = 0;
    cout << "Enter the number = ";
    cin >> num;

    // halfPyramid(num);
    invertedHalfPyramid(num);


    return 0;
}