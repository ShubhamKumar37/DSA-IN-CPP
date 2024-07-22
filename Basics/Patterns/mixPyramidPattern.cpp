#include<IOSTREAM>

using namespace std;

void mixPyramid(int num)
{
    for(int i = 0; i < num; i++)
    {
        // Stars part
        for(int j = 0; j < num - i; j++)
        {
            cout << "* ";
        }
        
        // Spaces part
        for(int j = 0; j < (2 * i + 1); j++)
        {
            cout << "  ";
        }

        // Stars Part
        for(int j = 0; j < num - i; j++)
        {
            cout << "* ";
        }

        cout << endl;
    }
    

    for(int i = 0; i < num; i++)
    {
        // Stars part
        for(int j = 0; j <= i; j++)
        {
            cout << "* ";
        }
        
        // Spaces part
        for(int j = 0; j < (2 * (num - i) - 1); j++)
        {
            cout << "  ";
        }

        // Stars Part
        for(int j = 0; j <= i; j++)
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

    mixPyramid(num);

    return 0;
}

// * _ _ _ _ _ _ _ *
// * * _ _ _ _ _ * *
// * * * _ _ _ * * *
// * * * * _ * * * *
