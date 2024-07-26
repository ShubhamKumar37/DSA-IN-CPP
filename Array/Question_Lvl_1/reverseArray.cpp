#include<IOSTREAM>

using namespace std;

void reverseArray(int arr[], int length)
{
    for(int i = 0; i < (length >> 1); i++)
    {
        swap(arr[i], arr[length - i - 1]);
    }
}

int main()
{
    int arr[] = {4, 5, 2, 5, 3, 8, 6, 9};
    int length = sizeof(arr) / sizeof(int);

    cout << "Before reverse = ";
    for(int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    reverseArray(arr, length);

    cout << "After reverse = ";
    for(int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}