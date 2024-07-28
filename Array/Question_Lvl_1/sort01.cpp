#include <IOSTREAM>
#include <algorithm>

using namespace std;

void sort01Method1(int arr[], int length)
{
    sort(arr, arr + length);
}

void sort01Method2(int arr[], int length)
{
    int count0 = 0;
    int count1 = 0;

    for(int i = 0; i < length; i++)
    {
        if(arr[i] == 0)
        {
            count0++;
        }
        else
        {
            count1++;
        }
    }

    fill(arr, arr + count0, 0);
    fill(arr + count0, arr + length, 1);

    return ;
}

void sort01Method3(int arr[], int length)
{
    int i = 0, j = length - 1;

    while(i < j)
    {
        while(arr[i] == 0) i++;
        while(arr[j] == 1) j--;

        if(i < j)
        {
            swap(arr[i], arr[j]);
            i++, j--;
        }
    }
}

int main()
{
    int arr[] = {0, 1, 0, 1, 0, 1, 1, 1, 0};
    int length = sizeof(arr) / sizeof(int);

    // sort01Method1(arr, length);
    sort01Method2(arr, length);
    // sort01Method3(arr, length);


    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}