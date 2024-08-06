#include <IOSTREAM>

using namespace std;

void moveToRight1(int arr[], int length)
{
    int i = 0, j = 0;

    while (j < length)
    {
        if (arr[j] < 0)
        {
            swap(arr[i], arr[j]);
            i++;
        }
        else if (arr[i] < 0)
        {
            i++;
        }

        j++;
    }

    cout << "After swaping the value" << endl;
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void moveToRight2(int arr[], int length)
{
    int i = 0, j = length - 1;

    while (i < j)
    {
        if (arr[i] < 0)
        {
            i++;
        }
        else if (arr[j] >= 0)
        {
            j--;
        }
        else
        {
            swap(arr[i], arr[j]);
            i++, j--;
        }
    }

    cout << "After swaping the value" << endl;
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {1, 2, -3, 4, -5, 6};
    // int arr[] = {-1, -2, -3, -4, -5, -6};
    // int arr[] = {1, 2, 3, 4, 5, 6};
    // int arr[] = {1, -1, 3, 2, -7, -5, 11, 6};
    int length = sizeof(arr) / sizeof(int);

    cout << "Before swaping the values " << endl;
    for (int i = 0; i < length; i++)
    {
        cout << i[arr] << " ";
    }
    cout << endl;

    // moveToRight1(arr, length);
    moveToRight2(arr, length);

    return 0;
}