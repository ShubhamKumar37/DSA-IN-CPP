#include<IOSTREAM>

using namespace std;

void butterflyPattern(int num)
{
    // Upper portion
    for(int i = 0; i < num; i++)
    {
        // Star printing
        for(int j = 0; j <= i; j++)
        {
            cout << "* ";
        }
        
        // Space printing
        for(int j = 0; j < (2 * num - 2 * (i + 1)); j++)
        {
            cout << "  ";
        }
        
        // Star printing
        for(int j = 0; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    // Lower portion
    for(int i = 0; i < num; i++)
    {
        // Star printing
        for(int j = 0; j < num - i; j++)
        {
            cout << "* ";
        }
        
        // Space printing
        for(int j = 0; j < i * 2; j++)
        {
            cout << "  ";
        }
        
        // Star printing
        for(int j = 0; j < num - i; j++)
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

    butterflyPattern(num);

    return 0;
}