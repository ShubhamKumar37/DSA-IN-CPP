#include <IOSTREAM>
#include <algorithm>

using namespace std;

void sort012Method1(int arr[], int length)
{
    sort(arr, arr + length);

    return ;
}

void sort012Method2(int arr[], int length)
{
    int i = 0, j = length - 1, k = 0;

    while(k <= j) // May be the last case have arr[k] == 0 then we will require to swap it with arr[i]
    {
        if(arr[k] == 0)
        {
            swap(arr[i], arr[k]);
            i++, k++;
        }
        else if(arr[k] == 2)
        {
            swap(arr[k], arr[j]);
            j--;
        }
        else if(arr[k] == 1)
        {
            k++;
        }
    }
}

int main()
{
    int arr[] = {0, 1, 0, 1, 0, 1, 1, 1, 0};
    // int arr[] = {0, 1, 0};
    int length = sizeof(arr) / sizeof(int);

    // sort012Method1(arr, length);
    sort012Method2(arr, length);

    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}