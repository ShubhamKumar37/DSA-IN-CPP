#include <IOSTREAM>

using namespace std;

int main()
{
    int length, breath;

    cout << "Enter the length = ";
    cin >> length;
    cout << "Enter the breath = ";
    cin >> breath;

    for (int i = 0; i < breath; i++)
    {
        for (int j = 0; j < length; j++)
        {

            if (i == 0 || i == breath - 1)
            {
                cout << "* ";
            }
            else
            {
                if (j == 0 || j == length - 1)
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