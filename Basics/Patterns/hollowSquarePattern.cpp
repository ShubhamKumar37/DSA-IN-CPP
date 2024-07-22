#include <IOSTREAM>

using namespace std;

int main()
{
    int side;
    cout << "Enter the side of hollow square = ";
    cin >> side;

    for (int i = 0; i < side; i++)
    {
        for (int j = 0; j < side; j++)
        {
            if (i == 0 || i == side - 1)
            {
                cout << "* ";
            }
            else
            {
                if (j == 0 || j == side - 1)
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

    return 0;
}