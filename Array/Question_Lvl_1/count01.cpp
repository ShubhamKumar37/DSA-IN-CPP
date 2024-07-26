#include<IOSTREAM>

using namespace std;

void count01(int arr[], int length)
{
    int count0 = 0;
    int count1 = 0;

    for(int i = 0; i < length; i++)
    {
        if(arr[i] == 0)
        {
            count0++;
        }
        else if(arr[i] == 1)
        {
            count1++;
        }
    }

    cout << "Number of 0 in the array = " << count0 << endl; 
    cout << "Number of 1 in the array = " << count1 << endl; 
}

int main()
{
    int arr[] = {0, 1, 0, 1, 0, 1, 1, 1, 0};
    int length = sizeof(arr) / sizeof(int);

    count01(arr, length);

    return 0;
}