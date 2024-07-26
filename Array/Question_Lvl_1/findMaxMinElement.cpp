#include<IOSTREAM>
#include<LIMITS>

using namespace std;

int findMax(int arr[], int length)
{
    int max = INT_MIN;

    for(int i = 0; i < length; i++)
    {
        if(max < arr[i])
        {
            max = arr[i];
        }
    }

    return max;
}
int findMin(int arr[], int length)
{
    int min = INT_MAX;

    for(int i = 0; i < length; i++)
    {
        if(min > arr[i])
        {
            min = arr[i];
        }
    }

    return min;
}

int main()
{
    int arr[] = {4, 3, 5, 6, 5, 3, 6, 2, 6, 7, -9, 1232};
    int length = sizeof(arr) / sizeof(int);

    cout << "This is the max element = " << findMax(arr, length) << endl;
    cout << "This is the max element = " << findMin(arr, length) << endl;


    return 0;
}