#include <IOSTREAM>

using namespace std;

void numericPalindromePyramid(int num)
{
    for (int i = 0; i < num; i++)
    {
        // Print spaces
        for (int j = 0; j < num - i - 1; j++)
        {
            cout << "  ";
        }

        // Print numbers
        int k = 0;
        for (int j = 0; j < (2 * i + 1); j++)
        {
            if (j <= ((2 * i + 1) / 2))
            {
                cout << ++k;
            }
            else
            {
                cout << --k;
            }
            cout << " ";
        }

        cout << endl;
    }
}

int main()
{
    int num = 0;
    cout << "Enter the number = ";
    cin >> num;

    numericPalindromePyramid(num);

    return 0;
}