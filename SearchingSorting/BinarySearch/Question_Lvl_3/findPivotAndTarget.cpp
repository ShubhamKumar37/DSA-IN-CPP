#include <iostream>
#include <vector>

using namespace std;

int findPivot(vector<int> &arr, int length)
{
    int s = 0, e = length - 1;
    int mid = s + ((e - s) >> 1);

    while (s < e)
    {
        if (mid + 1 < length && arr[mid] > arr[mid + 1])
        {
            return mid;
        }
        else if (mid - 1 >= 0 && arr[mid] < arr[mid - 1])
        {
            return mid - 1;
        }
        else if (arr[mid] >= arr[0])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }

        mid = s + ((e - s) >> 1);
    }

    return s;
}

int BS(vector<int> &arr, int s, int e, int length, int target)
{
    while (s <= e && s < length)
    {
        int mid = s + ((e - s) >> 1);

        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }

    return -1;
}

int main()
{
    vector<int> arr = {4};
    int length = arr.size();
    int target = 4;
    if (length == 1)
    {
        cout << "Element is founded at index  = " << (arr[0] == target ? 0 : -1) << endl;
    }

    int pivotIndex = findPivot(arr, length);

    if (arr[0] <= arr[pivotIndex] && arr[0] <= target)
    {
        cout << "Target is founded at index = " << BS(arr, 0, pivotIndex, length, target) << endl;
    }
    else
    {
        cout << "Target is founded at index = " << BS(arr, pivotIndex + 1, length - 1, length, target) << endl;
    }

    return 0;
}