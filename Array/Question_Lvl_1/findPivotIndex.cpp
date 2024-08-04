#include <IOSTREAM>
#include <VECTOR>

using namespace std;

int findPivot1(int arr[], int length)
{
    int sum = 0;

    for (int i = 0; i < length; i++)
    {
        int tempSum = 0;
        for (int j = i + 1; j < length; j++)
        {
            tempSum += arr[j];
        }

        if (tempSum == sum)
        {
            return i;
        }

        sum += arr[i];
    }

    return -1;
}

int findPivot2(int arr[], int length)
{
    int sum = 0;

    for (int i = 1; i < length; i++)
    {
        arr[i] = arr[i - 1] + arr[i];
    }

    for (int i = 0; i < length; i++)
    {
        if (sum == arr[length - 1] - arr[i])
        {
            return i;
        }

        sum = arr[i];
    }

    return -1;
}

int findPivot3(int arr[], int length)
{
    vector<int> leftSum(length, 0);
    vector<int> rightSum(length, 0);

    for(int i = 1; i < length; i++)
    {
        leftSum[i] = leftSum[i - 1] + arr[i - 1];
    }

    for(int i = length - 2; i >= 0; i--)
    {
        rightSum[i] = rightSum[i + 1] + arr[i + 1];
    }

    for(int i = 0; i < length; i++)
    {
        if(rightSum[i] == leftSum[i])
        {
            return i;
        }
    }

    return -1;
}

int main()
{

    int arr[] = {1, 7, 3, 6, 5, 6};
    int length = sizeof(arr) / sizeof(int);

    // cout << "Pivot index is " << findPivot1(arr, length) << endl;
    // cout << "Pivot index is " << findPivot2(arr, length) << endl;
    cout << "Pivot index is " << findPivot3(arr, length) << endl;

    return 0;
}