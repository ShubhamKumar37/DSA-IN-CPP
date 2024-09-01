#include <IOSTREAM>
#include <VECTOR>
#include <CMATH>

using namespace std;

bool isPossible(vector<int> &arr, int mid, int h)
{
    int count = 0;

    for (auto i : arr)
    {
        count += ceil((float)i / mid);

        if (count > h)
        {
            return false;
        }
    }
    return count <= h;
}

int findMinBanana(vector<int> &arr, int n, int h)
{
    int maxValue = INT_MIN;
    for (auto i : arr)
    {
        if (i > maxValue)
        {
            maxValue = i;
        }
    }

    int s = 1, e = maxValue;
    int mid = s + ((e - s) >> 1);
    int ans = -1;

    while (s <= e)
    {
        if (isPossible(arr, mid, h))
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
    vector<int> arr;
    int n, h;

    cin >> n >> h;

    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        arr.push_back(ele);
    }

    cout << "Koko can eat minimum of " << findMinBanana(arr, n, h) << " banana in 1 hour" << endl;

    return 0;
}