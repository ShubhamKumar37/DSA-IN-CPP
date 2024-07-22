#include<IOSTREAM>

using namespace std;

int findUnique(int arr[], int length)
{
    int uniqueNumber = 0;

    for(int i = 0; i < length; i++)
    {
        uniqueNumber = uniqueNumber ^ arr[i];
    }

    return uniqueNumber;
}

int main()
{
    int arr[] = {1, 2, 3, 2, 1, 5, 9, 5, 3};
    int length = sizeof(arr) / sizeof(int);

    cout << "Unique number in the array is " << findUnique(arr, length) << endl;

    return 0;
}