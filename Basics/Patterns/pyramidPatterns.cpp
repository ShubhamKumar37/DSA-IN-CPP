#include <IOSTREAM>

using namespace std;

void halfPyramid(int num)
{
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    return;
}

void invertedHalfPyramid(int num)
{
    for (int i = 0; i < num; i++)
    {
        for (int j = num - i - 1; j >= 0; j--)
        {
            cout << "* ";
        }
        cout << endl;
    }

    return;
}

void hollowPyramid(int num)
{
    for(int i = 0; i < num; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            if(i < 2 || i == num - 1 || j == 0 || j == i)
            {
                cout << "* ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

void invertedHollowPyramid(int num)
{
    for(int i = 0; i < num; i++)
    {
        for(int j = 0; j <= num - i - 1 ; j++)
        {
            if(i == 0 || j == 0 || i == num - 1 || j == num - i - 1)   
            {
                cout << "* ";
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
    int num;
    cout << "Enter the number = ";
    cin >> num;

    // halfPyramid(num);
    // invertedHalfPyramid(num);
    // hollowPyramid(num);
    invertedHollowPyramid(num);

    return 0;
}