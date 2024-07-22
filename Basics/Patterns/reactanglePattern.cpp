#include<IOSTREAM>

using namespace std; 


int main()
{
    int length;
    int breath;

    cout << "Enter the length = ";
    cin >> length;
    cout << "Enter the breath = ";
    cin >> breath;

    for(int i = 0; i < breath; i++)
    {
        for(int j = 0; j < length; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }


    return 0;
}