#include <IOSTREAM>
#include <ASSERT.H>

using namespace std;

void fancyStar12(int num)
{
    // if(num > 9)
    // {
    //     cout << "Invalid input\n";
    //     return ;
    // }
    assert(num <= 9);

    for (int i = 0; i < num; i++)
    {
        int startNum = 8 - i;
        int coutNum = i + 1;
        for (int j = 0; j < 17; j++)
        {
            if (j == startNum && coutNum > 0)
            {
                cout << i + 1;
                startNum += 2;
                coutNum--;
            }
            else
            {
                cout << "*";
            }
        }
        cout << endl;
    }
}

void fancyStart12HalfDiamond(int num)
{
    int temp = (num * (num + 1)) >> 1;
    int k = 1;

    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << k++;
            if (j != i)
            {
                cout << "*";
            }
        }
        cout << endl;
    }

    int startNum = temp - num;
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num - i; j++)
        {
            cout << startNum + j + 1;
            if (j < num - i - 1)
            {
                cout << "*";
            }
        }
        startNum = startNum - (num - i) + 1;
        cout << endl;
    }
}

void fancyStarHalfDiamond(int num)
{
    for (int i = 0; i < num; i++)
    {
        cout << "* ";

        int k = 1;
        for (int j = 0; j < (2 * i - 1); j++)
        {
            if (j < ((2 * i + 1) >> 1))
            {
                cout << j + 1;
            }
            else
            {
                cout << j - k;
                k += 2;
            }
            cout << " ";
        }
        if (i != 0)
        {
            cout << "* " << endl;
        }
        else
        {
            cout << endl;
        }
    }

    for (int i = 0; i < num - 1; i++)
    {
        cout << "* ";
        for (int j = 0; j < num - i - 1; j++)
        {
            if (j < num - i - 2)
            {
                cout << j + 1 << " ";
            }
            else
            {
                for (int k = 0; k < num - i - 3; k++)
                {
                    cout << j - k - 1 << " ";
                }
                break;
            }
        }
        if (i != num - 2)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

int main()
{
    int num = 0;
    cout << "Enter the number = ";
    cin >> num;

    // fancyStar12(num);
    // fancyStart12HalfDiamond(num);
    fancyStarHalfDiamond(num);

    return 0;
}