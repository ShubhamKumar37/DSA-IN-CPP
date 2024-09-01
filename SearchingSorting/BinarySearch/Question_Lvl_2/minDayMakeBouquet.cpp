#include <IOSTREAM>
#include <VECTOR>
#include <algorithm>

using namespace std;

bool isPossibleDay(vector<int> &arr, int mid, int m, int k)
{
    int count = 0;
    int ans = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (ans == m)
            return true;

        else if ((arr[i] - mid) <= 0)
        {
            count++;

            if (count == k)
            {
                ans++;
                count = 0;
            }
        }

        else
            count = 0;
    }

    return ans == m;
}

int findMinDays(vector<int> &arr, int m, int k)
{
    if (arr.size() < m || arr.size() < k || arr.size() < (m * k))
        return -1;

    int s = *min_element(arr.begin(), arr.end());
    int e = *max_element(arr.begin(), arr.end());
    int ans = s;

    while (s <= e)
    {
        int mid = s + ((e - s) >> 1);

        if (isPossibleDay(arr, mid, m, k))
        {
            ans = mid;
            e = mid - 1;
        }
        else
            s = mid + 1;
    }

    return ans;
}

int main()
{
    vector<int> arr;
    int m, k;

    cin >> m >> k;

    for (;;)
    {
        int ele;
        cin >> ele;
        if (ele == -1)
            break;

        arr.push_back(ele);
    }

    cout << "Possible days to make " << m << " bouquets is " << findMinDays(arr, m, k) << endl;

    return 0;
}