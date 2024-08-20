#include <IOSTREAM>
#include <VECTOR>

using namespace std;

int findPeakMountain(vector<int> &arr, int length)
{
    int s = 0, e = length - 1;
    int mid = s + ((e - s) >> 1);

    while (s < e)
    {
        if (arr[mid] < arr[mid + 1])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }

        mid = s + ((e - s) >> 1);
    }

    // All these pointer will point to the answer
    // return s;
    // return e;
    return mid;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 3, 2, 1};
    int length = arr.size();

    cout << "Peak mountain element is " << arr[findPeakMountain(arr, length)] << endl;

    return 0;
}