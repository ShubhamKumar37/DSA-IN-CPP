#include<IOSTREAM>
#include<VECTOR>
#include<algorithm>

using namespace std;

int findMissingBS(vector<int> &arr, int &length)
{
    int s = 0, e = length - 1;
    int mid = s + ((e - s) >> 1);
    int ans = length;

    while(s <= e)
    {
        if(arr[mid] != mid)
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }

        mid = s + ((e - s) >> 1);
    }

    return ans;
}

int main()
{

    // Find missing element in an array of distinct numbers, range of number is [0, n].

    vector<int> arr = {1, 2, 3, 4, 5, 7, 8, 9, 6, 0};
    int length = arr.size();

    sort(arr.begin(), arr.end());

    cout << "This is the missing element " << findMissingBS(arr, length);


    return 0;
}