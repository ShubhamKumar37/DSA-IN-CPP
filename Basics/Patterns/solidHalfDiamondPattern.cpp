#include<IOSTREAM>

using namespace std;

void solidHalfDiamond1(int num)
{
    for(int i = 0; i < num; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    for(int i = 0; i < num - 1; i++)
    {
        for(int j = 0; j < num - i - 1; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void solidHalfDiamond2(int num)
{
    int k = 0;
    for(int i = 0; i < (2 * num - 1); i++)
    {
        if(i < (num))
        {
            for(int j = 0; j <= i; j++)
            {
                cout << "* ";
            }
        }
        else
        {
            for(int j = 0; j < num - k - 1; j++)
            {
                cout << "* ";
            }
            k++;
        }
        cout << endl;
    }
}

int main()
{
    int num = 0;
    cout << "Enter the number = ";
    cin >> num;

    // solidHalfDiamond1(num);
    solidHalfDiamond2(num);

    return 0;
}