#include <IOSTREAM>
#include <VECTOR>

using namespace std;

int findPeak(vector<int> &arr, int length)
{
    int s = 0, e = length - 1;
    int mid = s + ((e - s) >> 1);

    while (s < e)
    {
        if (mid > 0 && arr[mid - 1] < arr[mid]) s = mid + 1;
        else e = mid;

        mid = s + ((e - s) >> 1);
    }

    if (s == 0 || arr[s] > arr[s - 1]) return s;

    return s - 1;
}

int main()
{
    vector<int> arr;

    for (;;)
    {
        int ele;
        cin >> ele;
        if (ele == -1)
            break;

        arr.push_back(ele);
    }

    cout << "One of the peak element of array is " << arr[findPeak(arr, arr.size())] << endl;

    return 0;
}