#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.
All the integers in nums appear only once except for precisely one integer which appears two or more times.
 */

int findDuplicate1(int arr[], int length)
{
    int ans = -1;
    sort(arr, arr + length);

    for (int i = 1; i < length; i++)
    {
        if (arr[i] == arr[i - 1])
        {
            ans = arr[i];
            break;
        }
    }

    return ans;
}

int findDuplicate2(int arr[], int length)
{
    int ans = -1;

    for (int i = 0; i < length; i++)
    {
        int index = abs(arr[i]);
        if (arr[index] < 0)
        {
            ans = index;
            break;
        }

        arr[index] = -1 * arr[index];
    }

    return ans;
}

int findDuplicate3(int arr[], int length)
{
    // 3 2 1 3
    // 3 2 1 3 at this point nums[0] == nums[nums[0]] so automaticall nums[0] is the duplicate element
    while (arr[0] != arr[arr[0]])
    {
        swap(arr[0], arr[arr[0]]);
    }

    return arr[0];
}

int main()
{
    int arr[] = {3, 2, 1, 3};
    int length = sizeof(arr) >> 2;

    // cout << "The duplicate element is " << findDuplicate1(arr, length) << endl;
    // cout << "The duplicate element is " << findDuplicate2(arr, length) << endl;
    cout << "The duplicate element is " << findDuplicate3(arr, length) << endl;

    return 0;
}