#include<iostream>

using namespace std;

void printAllPairs(int arr[], int length)
{
    for(int i = 0; i < length; i++)
    {
        for(int j = 0; j < length; j++)
        {
            cout << arr[i] << ", " << arr[j] << endl;
        }
    }
}

void trianglePattern1(int arr[], int length)
{
    for(int i = 0; i < length; i++)
    {
        for(int j = i; j < length; j++)
        {
            cout << arr[i] << ", " << arr[j] << endl;
        }
    }
}

void trianglePattern2(int arr[], int length)
{
    for(int i = 0; i < length; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            cout << arr[i] << ", " << arr[j] << endl;
        }
    }
}

int main()
{
    int arr[] = {10, 20, 30, 40};
    int length = sizeof(arr) / sizeof(int);

    // printAllPairs(arr, length);
    // trianglePattern1(arr, length);
    trianglePattern2(arr, length);


    return 0;
}