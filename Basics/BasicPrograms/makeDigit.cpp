#include<IOSTREAM>

using namespace std;

int main()
{
    long long finalNumber = 0;
    
    for(;;)
    {
        int num = 0;
        cout << "Enter the integer = ";
        cin >> num;

        if(num > 9)
        {
            break;
        }

        finalNumber = finalNumber * 10 + num;
    }
    
    cout << "The final number is " << finalNumber << endl;

    return 0;
}