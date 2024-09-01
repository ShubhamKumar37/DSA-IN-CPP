#include <IOSTREAM>
#include <VECTOR>

using namespace std;

int findElement(vector<int> &arr, int length)
{
    int s = 0, e = length - 1;
    int mid = s + ((e - s) >> 1);

    while (s < e)
    {
        if(mid & 1 == 1)
        {
            // Odd
            if(mid + 1 < length && arr[mid] == arr[mid + 1])
            {
                e = mid;
            }
            else
            {
                s = mid + 1;
            }
        }
        else
        {
            // Even
            if(mid + 1 < length && arr[mid] != arr[mid + 1])
            {
                e = mid;
            }
            else
            {
                s = mid + 1;
            }
        }

        mid = s + ((e - s) >> 1);
    }

    return mid;
}

int main()
{
    // vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 5, 5, 7, 7, 8, 8, 9};
    // vector<int> arr = {1, 1, 2, 3, 3, 4, 4, 5, 5};
    // vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 4, 5};
    // vector<int> arr = {1, 2, 2, 3, 3, 4, 4, 5, 5};
    // vector<int> arr = {-1, -2, -2, -3, -3};
    vector<int> arr = {1,1,2,3,3,4,4,8,8};
    int length = arr.size();
    int index = findElement(arr, length);

    cout << "Unique element index is " << index << endl;

    return 0;
}