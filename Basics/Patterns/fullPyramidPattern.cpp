#include<IOSTREAM>

using namespace std;

void fullPyramid(int num)
{
    // for(int i = 0; i < num; i++)
    // {
    //     for(int j = 0; j < num - i - 1; j++)
    //     {
    //         cout << " ";
    //     }
    //     for(int j = 0; j <= i; j++)
    //     {
    //         cout << "* ";
    //     }
    //     cout << endl;
    // }

    for(int i = 0; i < num; i++)
    {
        for(int j = 0; j < num; j++)
        {
            if(j < num - i - 1)
            {
                cout << " ";
            }
            else
            {
                cout << "* ";
            }
        }
        cout << endl;
    }
}

void invertedFullPyramid(int num)
{
    for(int i = 0; i < num; i++)
    {
        for(int j = 0; j < num; j++)
        {
            if(j < i)
            {
                cout << " ";
            }
            else
            {
                cout << "* ";
            }
        }
        cout << endl;
    }
}

void fullDiamond(int num)
{
    fullPyramid(num);
    invertedFullPyramid(num);
}

int main()
{
    int num = 0;
    cout << "Enter the number = ";
    cin >> num;

    // fullPyramid(num);
    // invertedFullPyramid(num);
    fullDiamond(num);

    return 0;
}