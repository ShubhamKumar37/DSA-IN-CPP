#include <IOSTREAM>

using namespace std;

void rotateArray1(int arr[], int length, int n)
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

void reverse(int arr[], int low, int high)
{
    while (low < high)
    {
        swap(arr[low], arr[high]);
        low++, high--;
    }
}

void rotateArray2(int arr[], int length, int n)
{
    n = n % length;

    if (n == 0)
    {
        return;
    }

    reverse(arr, 0, length - 1);
    reverse(arr, 0, n - 1);
    reverse(arr, n, length - 1);
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int length = sizeof(arr) / sizeof(int);
    int n = 12;

    // rotateArray1(arr, length, n);
    rotateArray2(arr, length, n);

    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}