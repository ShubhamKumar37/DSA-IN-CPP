#include <IOSTREAM>

using namespace std;

void fancyPattern12(int num)
{
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << j + 1;
            if (j != i)
            {
                cout << " * ";
            }
        }
        cout << endl;
    }
}

void fullFancyPattern12(int num)
{
    fancyPattern12(num);
    num--;

    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num - i; j++)
        {
            cout << num - i;
            if (j != num - i - 1)
            {
                cout << " * ";
            }
        }
        cout << endl;
    }
}

void fancyPatternABC(int num)
{
    if (num > 26)
    {
        cout << "Please enter the number less than 26" << endl;
        return;
    }
    for (int i = 0; i < num; i++)
    {
        // Ordered alphabets
        for (int j = 0; j <= i; j++)
        {
            cout << (char)('A' + j);
        }

        // Reverse order alphabets
        for (int j = 0; j < i; j++)
        {
            cout << (char)('A' + i - (j + 1));
        }

        cout << endl;
    }
}

int main()
{
    int num = 0;
    cout << "Enter the number = ";
    cin >> num;

    // fancyPattern12(num);
    // fullFancyPattern12(num);
    fancyPatternABC(num);

    return 0;
}