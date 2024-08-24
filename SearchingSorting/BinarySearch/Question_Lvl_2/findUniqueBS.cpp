#include <IOSTREAM>
#include <VECTOR>

using namespace std;

int findElement(vector<int> &arr, int length)
{
    int s = 0, e = length - 1;
    int mid = s + ((e - s) >> 1);
    int ans = -1;

    while (s <= e)
    {
        cout << "mid = " << mid << endl;
        cout << "arr[mid] = " << arr[mid] << endl;
        cout << "s = " << s << endl;
        cout << "e = " << e << endl
             << endl;

        if(mid & 1 == 1)
        {
            // Odd
            if(arr[mid] == arr[mid + 1])
            {
                s = mid + 1;
            }
            else
            {
                ans = mid + 1;
                // cout << "ans = " << ans << endl;
                e = mid - 1;
            }
        }
        else 
        {
            // Even
            if(arr[mid] == arr[mid + 1])
            {
                s = mid + 1;
            }
            else 
            {
                ans = mid;
                // cout << "ans = " << ans << endl;
                e = mid - 1;
            }
        }

        // cout << "ans = " << ans << endl;
        mid = s + ((e - s) >> 1);
    }

    return ans;
}

int main()
{
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 5, 5, 7, 7, 8, 8, 9};
    int length = arr.size();
    int index = findElement(arr, length);

    cout << "Unique element is " << (index == -1 ? -1 : index) << endl;

    return 0;
}