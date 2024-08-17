#include <IOSTREAM>
#include <VECTOR>
#include <algorithm>

using namespace std;

int findElement(vector<int> &arr, int length, int target)
{
    int s = 0, e = length - 1;
    int mid = s + ((e - s) >> 1);

    while (s <= e)
    {
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

        mid = s + ((e - s) >> 1);
    }

    return -1;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 9};
    int length = arr.size();
    int target = 8;

    // cout << "Target found at " << findElement(arr, length, target) << endl;
    cout << "Target is present in array = " << binary_search(arr.begin(), arr.end(), target) << endl;

    return 0;
}