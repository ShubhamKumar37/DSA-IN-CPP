#include<IOSTREAM>

using namespace std;

void numericHollowHalfPyramid(int num)
{
    for(int i = 0; i < num; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            if(j == 0 || j == i || i == num - 1)
            {
                cout << j + 1 << " ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

void numericHollowInvertedHalfPyramid(int num)
{
    for(int i = 0; i < num; i++)
    {
        for(int j = 0; j < num - i; j++)
        {
            if(i == 0 || j == 0 || j == num - i - 1)
            {
                cout << j + i + 1 << " ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

int main()
{
    int num = 0;
    cout << "Enter the number = ";
    cin >> num;

    // numericHollowHalfPyramid(num);
    numericHollowInvertedHalfPyramid(num);

    return 0;
}