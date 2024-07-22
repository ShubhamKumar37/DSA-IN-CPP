#include <IOSTREAM>

using namespace std;

void hollowFullPyramid(int num)
{
    for (int i = 0; i < num; i++)
    {
        // for(int j = 0; j < num - i - 1; j++)
        // {
        //     cout << " ";
        // }

        // for(int j = num - i - 1; j < num; j++)
        // {
        //     if(i == num - 1 || j == num - i - 1 || j == num - 1)
        //     {
        //         cout << "* ";
        //     }
        //     else
        //     {
        //         cout << "  ";
        //     }
        // }

        for (int j = 0; j < num; j++)
        {
            if (j < num - i - 1)
            {
                cout << " ";
            }
            else if (i == num - 1 || j == num - i - 1 || j == num - 1)
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
    for (int i = 0; i < num; i++)
    {
        // for(int j = 0; j < i; j++) cout << " ";

        // if(i == 0)
        // {
        //     for(int j = 0; j < num; j++)
        //     {
        //         cout << "* ";
        //     }
        // }
        // else
        // {
        //     for(int j = i; j < num; j++)
        //     {
        //         if(j == i || j == num - 1)
        //         {
        //             cout << "* ";
        //         }
        //         else
        //         {
        //             cout << "  ";
        //         }

        //     }
        // }

        for (int j = 0; j < num; j++)
        {
            if (i == 0)
            {
                cout << "* ";
            }
            else
            {
                if (j < i)
                {
                    cout << " ";
                }
                else if (j == i || j == num - 1)
                {
                    cout << "* ";
                }
                else
                {
                    cout << "  ";
                }
            }
        }
        cout << endl;
    }
}

void hollowDiamond(int num)
{
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            if (j < num - i - 1)
            {
                cout << " ";
            }
            else if (i == num - 1)
            {
                cout << "* ";
                for (int k = j + 1; k < num - 1; k++)
                    cout << "  ";
                cout << "* ";
                break;
            }
            else if (j == num - i - 1 || j == num - 1)
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

    for (int i = 0; i < num; i++)
    {

        for (int j = 0; j < num; j++)
        {
            if (i == 0)
            {
                cout << "* ";
                for (int k = j + 1; k < num - 1; k++)
                    cout << "  ";
                cout << "* ";
                break;
            }
            else
            {
                if (j < i)
                {
                    cout << " ";
                }
                else if (j == i || j == num - 1)
                {
                    cout << "* ";
                }
                else
                {
                    cout << "  ";
                }
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

    // hollowFullPyramid(num);
    // invertedHollowPyramid(num);
    hollowDiamond(num);

    return 0;
}