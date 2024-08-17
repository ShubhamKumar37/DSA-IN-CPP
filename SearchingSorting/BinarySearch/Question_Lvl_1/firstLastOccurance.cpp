#include <IOSTREAM>
#include <VECTOR>

using namespace std;

int findFirstOccurance(vector<int> &arr, int length, int target)
{
    int s = 0, e = length - 1;
    int mid = s + ((e - s) >> 1);
    int ans = -1;

    while (s <= e)
    {
        if (arr[mid] == target)
        {
            ans = mid;
            e = mid - 1;
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

    return ans;
}

int findLastOccurance(vector<int> &arr, int length, int target)
{
    int s = 0, e = length - 1;
    int mid = s + ((e - s) >> 1);
    int ans = -1;

    while (s <= e)
    {
        if (arr[mid] == target)
        {
            ans = mid;
            s = mid + 1;
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

    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 2, 2, 3, 4, 5, 6, 6, 7, 8, 9};
    int length = arr.size();
    int target = 9;

    cout << "Element first occurance is " << findFirstOccurance(arr, length, target) << endl;
    cout << "Element last occurance is " << findLastOccurance(arr, length, target) << endl;

    return 0;
}