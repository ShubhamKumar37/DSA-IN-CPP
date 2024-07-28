#include <IOSTREAM>

using namespace std;

void rotateArray(int arr[], int length, int n)
{

    n = n % length;
    if (n == 0)
    {
        return;
    }

    int *newArr = new int[n];

    for (int i = length - n, j = 0; i < length; i++, j++)
    {
        newArr[j] = arr[i];
    }
    for (int i = length - 1; i >= n; i--)
    {
        swap(arr[i - n], arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = newArr[i];
    }
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int length = sizeof(arr) / sizeof(int);
    int n = 8;

    rotateArray(arr, length, n);

    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}